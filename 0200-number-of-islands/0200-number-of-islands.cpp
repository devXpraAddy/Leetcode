class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& vis, int n, int m, vector<vector<char>>& grid){
        vis[i][j] = 1;

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<int>delRow = {-1, 0, 1, 0};
            vector<int>delCol = {0, -1, 0, 1};

            for(int i = 0; i<4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(newRow >=0 && newCol >=0 && newRow <n && newCol <m && grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                    vis[newRow][newCol] =1;
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

        for(int i =0 ;i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i, j, vis, n, m, grid);
                }
            }
        }
        return cnt;
    }
};

