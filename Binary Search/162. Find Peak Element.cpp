//  https://leetcode.com/problems/find-peak-element/description/

// Brute Force
// T.C: O(n)
// S.C: O(1)

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        else if (nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }
        else
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// Using Binary Search

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0; // first element
        if (nums[n - 1] > nums[n - 2])
            return n - 1;          // last element
        int low = 1, high = n - 2; // we are not checking for the first and the last element
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};