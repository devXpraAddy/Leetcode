class Solution {
public:
    int t[201][201];
    int solve(int m, int n, vector<vector<int>>& grid){
        if(m == 0 && n== 0) return grid[m][n];
        if(m<0 || n<0) return 1e9+7;

        if(t[m][n] != -1){
            return t[m][n];
        }

        int left = grid[m][n] + solve(m, n-1, grid);
        int up = grid[m][n] + solve(m-1, n, grid);
        return t[m][n] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        int m = grid.size();
        int n = grid[0].size();

        return solve(m-1, n-1, grid);
    }
};