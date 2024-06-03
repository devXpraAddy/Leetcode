// https://leetcode.com/problems/first-missing-positive/

// Using Extra space map
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = true;
        }
        int missing = 1;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(missing) != mp.end())
            {
                missing++;
            }
        }
        return missing;
    }
};

// Using O(1) space and same pattern - "Using numbers as indices"
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        bool contains1 = false;

        for (int i = 0; i < n; i++)
        {
            // Check whether 1 is in the original array
            if (nums[i] == 1)
            {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n)
            { // checking for range [1,n]
                nums[i] = 1;
            }
        }

        if (!contains1) // contains1 = false
            return 1;

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
        for (int i = 0; i < n; i++)
        {

            int val = abs(nums[i]);
            int idx = val - 1;

            if (nums[idx] < 0)
                continue; // check if the no. is already negative
            nums[idx] *= -1;
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) // this means that we never came at this index
                return i + 1;
        }

        return n + 1; // if every element is present then return n+1
    }
};

// using cyclic sort
class Solution
{
public
    int firstMissingPositive(int[] nums)
    {

        // the first two conditions in the if statement take care
        // that negatives and elements greater than the size of
        // the array are ignored, while applying cycle sort, and
        // rest is the similar code of cycle sort

        int i = 0;
        while (i < nums.length)
        {
            int correct = nums[i] - 1;
            if (nums[i] <= nums.length && nums[i] > 0 && nums[i] != nums[correct])
            {

                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            }
            else
            {
                i++;
            }
        }

        int count = 0;

        // after cycle sort has been applied, we will find the first element
        // which is not at the correct index, and return that index + 1

        for (int j = 0; j < nums.length; j++)
        {

            if (nums[j] != j + 1)
            {
                return j + 1;
            }
        }

        // if every element is at its correct index, then obviously the first
        // missing positive integer is nums.length + 1

        return nums.length + 1;
    }
}