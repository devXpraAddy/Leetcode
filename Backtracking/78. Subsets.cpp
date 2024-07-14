// https://leetcode.com/problems/subsets/description/

class Solution
{
public:
    vector<vector<int>> result;
    void solve(vector<int> &nums, int idx, vector<int> temp)
    {
        if (idx >= nums.size())
        {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);  // Take
        solve(nums, idx + 1, temp); // explore
        temp.pop_back();            // Not take
        solve(nums, idx + 1, temp); // explore
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;

        solve(nums, 0, temp);
        return result;
    }
};