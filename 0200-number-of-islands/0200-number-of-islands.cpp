class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        while (!q.empty()) {
            int roww = q.front().first;
            int coll = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = roww + delRow[i];
                int newCol = coll + delCol[i];
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
