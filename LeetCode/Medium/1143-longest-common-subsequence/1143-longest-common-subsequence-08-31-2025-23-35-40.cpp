class Solution {
private:
    int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>&dp){
        if(idx1 < 0 || idx2 <0) return 0; // -ve means end of the string

        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
        }
        return dp[idx1][idx2] = max(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>>dp(n1, vector<int>(n2, -1));

        return solve(n1-1, n2-1, text1, text2, dp);
    }
};