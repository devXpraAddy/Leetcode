class Solution {
private:
    int solve(int idx, int prev_idx, vector<int>&nums, vector<vector<int>>&dp){
        if(idx == nums.size()) return 0;

        if(dp[idx][prev_idx+1] != -1){
            return dp[idx][prev_idx+1];
        }

        int take = INT_MIN;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            take = 1 + solve(idx + 1, idx, nums, dp);
        }
        int skip = 0 + solve(idx + 1, prev_idx, nums, dp);

        return dp[idx][prev_idx+1] = max(take, skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};