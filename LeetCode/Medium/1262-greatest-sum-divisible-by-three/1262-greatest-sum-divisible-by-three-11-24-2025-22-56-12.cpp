class Solution {
private:
    int solve(int idx, int rem, vector<int>& nums, vector<vector<int>>&dp){
        if(idx < 0){
            return (rem == 0) ? 0 : INT_MIN;
        }

        if(dp[idx][rem] != -1){
            return dp[idx][rem];
        }

        int take = nums[idx] + solve(idx -1, (rem+nums[idx])%3, nums, dp);
        int skip = solve(idx-1,rem, nums, dp);

        return dp[idx][rem] = max(take, skip);

    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(3, -1));
        return solve(n-1,0, nums, dp);
    }
};