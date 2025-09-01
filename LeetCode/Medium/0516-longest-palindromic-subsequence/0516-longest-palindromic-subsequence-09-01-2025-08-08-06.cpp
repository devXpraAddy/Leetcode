class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return LPS(s, 0, n - 1, t);
    }

private:
    int LPS(string& s, int i, int j, vector<vector<int>>& t) {
        if(i > j)
            return 0;
        if(i == j)
            return 1; // only one character, so it will always be a palindrome

        if(t[i][j] != -1)
            return t[i][j];

        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i + 1, j - 1, t);
        else
            return t[i][j] = max(LPS(s, i + 1, j, t), LPS(s, i, j - 1, t));
    }
};
