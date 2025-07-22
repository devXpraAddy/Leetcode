class Solution {
private:
    int solve(int idx, vector<int>& nums, int n, vector<int>& dp){
        if(idx >= n) return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }

        int take = nums[idx] + solve(idx+2, nums, n, dp);
        int skip = solve(idx+1, nums, n, dp);
        return dp[idx] = max(take, skip);
    }
public:
    int rob(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        vector<int>dp(n, -1);

        return solve(0, nums, n, dp);
    }
};