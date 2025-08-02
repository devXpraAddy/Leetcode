class Solution {
private:
    bool solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return nums[idx] == target;

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int take = false;
        if(target >= nums[idx]){
            take = solve(idx -1, nums, target - nums[idx], dp);
        }
        int skip = solve(idx-1, nums, target, dp);

        return dp[idx][target] = take | skip;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;

        for(int i =0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;

        int target = sum/2;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));


        return solve(n-1, nums, target, dp);
    }
};