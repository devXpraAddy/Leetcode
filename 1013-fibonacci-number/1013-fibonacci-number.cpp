class Solution {
public:
    int fib(int n) {
        if(n== 0) return 0;
        vector<int>dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i =2; i<=n; i++){
            int left = dp[i-1];
            int right = dp[i-2];

            dp[i] = left + right;
        }

        return dp[n];
    }
};