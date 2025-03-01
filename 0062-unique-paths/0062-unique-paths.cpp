class Solution {
public:
    int t[101][101];
    int solve(int m, int n) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;

        if(t[m][n] != -1){
            return t[m][n];
        }
            
        int up = solve(m-1, n);
        int left = solve(m, n-1);
        return t[m][n] = up + left;
    }

    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(m-1,n-1);
    }
};
