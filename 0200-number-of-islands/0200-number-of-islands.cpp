class Solution {
private:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();



        while (!q.empty()) { // iterate on queue
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // traverse in the neighbour and mark them
            for (int i = 0; i <4; i++) {
                
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                        grid[nRow][nCol] == '1' && !vis[nRow][nCol]) {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

