#include <bits/stdc++.h>

using namespace std;

class Solutions
{
public:
    int t[2502][2502];
    int solve(vector<int> &nums, int preIdx, int currIdx)
    {
        int n = nums.size();
        if (currIdx == n)
        {
            return 0;
        }
        if (preIdx != -1 && t[preIdx][currIdx] != -1)
        {
            return t[preIdx][currIdx];
        }
        int take = 0;
        if (preIdx == -1 || nums[preIdx] < nums[currIdx])
        {
            take = 1 + solve(nums, currIdx, currIdx + 1);
        }
        int skip = solve(nums, preIdx, currIdx + 1);
        if (preIdx != -1)
        {
            t[preIdx][currIdx] = max(take, skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        memset(t, -1, sizeof(t));
        return solve(nums, -1, 0);
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solutions sol;
    int result = sol.lengthOfLIS(nums);
    cout << "Result: " << result;
}
