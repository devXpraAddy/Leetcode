class Solution {
    int dfs(int i, int n, int a, int b, int c, vector<vector<vector<vector<int>>>> &dp, int mod) {
        if(i == n) return 1;
        if(dp[i][a][b][c] != -1) return dp[i][a][b][c];
        
        int ans = 0;
        for(int c1=1; c1<=3; c1++) {
            if(c1 == a) continue;
            for(int c2=1; c2<=3; c2++) {
                if(c2 == b || c2 == c1) continue;
                for(int c3=1; c3<=3; c3++) {
                    if(c3 == c || c3 == c2) continue;
                    ans = (ans + dfs(i + 1, n, c1, c2, c3, dp, mod)) % mod;
                }
            }
        }
        return dp[i][a][b][c] = ans;
    }
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return dfs(0, n, 0, 0, 0, dp, mod);
    }
};