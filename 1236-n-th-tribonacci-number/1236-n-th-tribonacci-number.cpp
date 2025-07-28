class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int>dp(n+1, -1);
        dp[0] =0;
        dp[1] =1;
        dp[2] =1;

        for(int i = 3; i<=n; i++){
            int a = dp[i-1];
            int b = dp[i-2];
            int c = dp[i-3];

            dp[i] = a+b+c;
        }

        return dp[n];
    }
};