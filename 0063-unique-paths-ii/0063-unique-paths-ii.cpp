class Solution {
public:
    int t[101][101];
    int solve(int m, int n, vector<vector<int>>& grid){
        if(m == 0 && n == 0) return 1;
        if(m<0 || n<0 || grid[m][n] ==1) return 0;

        if(t[m][n] != -1) return t[m][n];

        int up = solve(m-1, n, grid);
        int left = solve(m, n-1, grid);
        return t[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
        return solve(m-1, n-1, grid);
    }
};
