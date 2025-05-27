class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cntFresh = 0;

        queue<pair<pair<int,int>, int>> q;

        vector<vector<int>>vis(n, vector<int>(m,0)); //initialize 2D vector with diff dimentions

        for(int i =0;i <n; i++){
            for(int j = 0;j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }else if(grid[i][j] == 1){
                    cntFresh++;
                }
                //else{
                //     vis[i][j] = 0;// initialization if vis
                // }
            }
        }

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        int maxTime =0;
        int cnt=0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxTime = max(maxTime, time);

            for(int i =0 ;i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >=0 && ncol >=0 && nrow<n && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});
                    cnt++; // every time when we are getting a fresh orange we are pushing it in queue
                }
            }
        }
        if(cnt != cntFresh) return -1;
        return maxTime;
    }
};
