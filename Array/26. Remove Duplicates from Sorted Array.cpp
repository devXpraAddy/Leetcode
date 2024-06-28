// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// My solution
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;
        int j = i + 1;

        while (i < n - 1 && j < n)
        {
            if (nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i + 1;
    }
};

// East solution
int removeDuplicates(vector<int> &nums)
{
    set<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans.insert(nums[i]);
    }
    nums.clear();
    for (auto &x : ans)
    {
        nums.push_back(x);
    }
    return nums.size();
}

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        unordered_set<int> uniqueSet;
        int writeIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (uniqueSet.count(nums[i]) == 0)
            {
                uniqueSet.insert(nums[i]);
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        return writeIndex;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<int, greater<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            ans.insert(nums[i]);
        }

        for (auto i : ans)
        {
            nums.insert(nums.begin(), i);
        }

        return ans.size();
    }
};