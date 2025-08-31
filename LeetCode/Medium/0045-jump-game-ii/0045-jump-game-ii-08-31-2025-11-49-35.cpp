class Solution {
private:
    int solve(int idx, vector<int>& nums, vector<int>&dp){
        if(idx >= nums.size()-1) return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int mini = 1e9;
        for(int i = 1; i<=nums[idx]; i++){ // current index se kitna jump kar sakte 
        //i != 0 coz curr index se jump ke baad we don't want to reach on the same idx
            mini = min(mini, 1 + solve(idx+i, nums, dp)); // as we need to find no. of jumps
            // so +1 for each jump similar to coin change 1
        }
        return dp[idx] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};