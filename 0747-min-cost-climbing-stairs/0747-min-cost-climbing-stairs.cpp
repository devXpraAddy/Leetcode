class Solution {
private:
    int solve(int idx, vector<int>& cost, vector<int>& dp){
        if(idx == 0|| idx == 1) return cost[idx];

        if(dp[idx] != -1){
            return dp[idx];
        }

        int left = cost[idx] + solve(idx -1, cost, dp);
        int right = cost[idx] + solve(idx -2, cost, dp);

        return dp[idx] = min(left, right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int>dp(n+1, -1);

        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};