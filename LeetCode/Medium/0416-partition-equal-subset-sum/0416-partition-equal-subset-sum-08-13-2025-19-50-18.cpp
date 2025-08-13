class Solution {
private:
    bool solve(int idx, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return arr[idx] == target;

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int take = false;
        if(target >= arr[idx]){
            take = solve(idx -1, target - arr[idx], arr, dp);
        }
        int skip = solve(idx -1, target, arr, dp);
        return dp[idx][target] = take | skip;
    }
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


        return solve(n-1, k, nums, dp);
    }
};

