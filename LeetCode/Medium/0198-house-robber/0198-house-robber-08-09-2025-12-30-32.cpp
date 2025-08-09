class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, -1);

        dp[0] = nums[0];

        for(int idx =1; idx<n; idx++){
            int take = nums[idx];
            if(idx > 1){
                take = take + dp[idx-2];
            }
            int skip = dp[idx-1];

            dp[idx] = max(take, skip);
        }
        return dp[n-1];
    }
};
