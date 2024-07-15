// https://leetcode.com/problems/subsets-ii/description/

class Solution
{
public:
    void solve(vector<int> &nums, int idx, vector<int> &temp, set<vector<int>> &result)
    {
        if (idx >= nums.size())
        {
            result.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, result);
        temp.pop_back();
        solve(nums, idx + 1, temp, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> result;
        solve(nums, 0, temp, result);
        vector<vector<int>> finalResult(result.begin(), result.end());
        return finalResult;
    }
};