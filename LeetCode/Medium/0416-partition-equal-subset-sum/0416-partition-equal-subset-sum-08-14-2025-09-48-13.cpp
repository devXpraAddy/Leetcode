class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;

        for(int i =0;i<n; i++){
            sum += nums[i];
        }
        if(sum %2 != 0) return false;

        int k = sum/2;

        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        
        for(int idx =0; idx < n; idx++){
            dp[idx][0] = true; 
        }
        if(k>= nums[0]){
            dp[0][nums[0]] = true;
        }

        for(int idx = 1; idx<n; idx++){
            for(int target = 1; target<= k; target++){
                int take = false;
                if(target >= nums[idx]){
                    take = dp[idx - 1][target - nums[idx]];
                }
                int skip = dp[idx-1][target];
                dp[idx][target] = take || skip;
            }
        }
        return dp[n-1][k];
    }
};

