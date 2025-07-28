class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        if(dp[n] != -1){
            return dp[n];
        }

        int a = solve(n-1, dp);
        int b = solve(n-2, dp);
        int c = solve(n-3, dp);

        return dp[n] = a+b+c;
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1, -1);

        return solve(n, dp);
    }
};