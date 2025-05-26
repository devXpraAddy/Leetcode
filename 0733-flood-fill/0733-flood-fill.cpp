class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, int initColor, vector<vector<int>>& res, int finalColor){
        res[row][col] = finalColor;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        q.push({row, col});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        while(!q.empty()){
            int roww = q.front().first;
            int coll = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newRow = roww + delRow[i];
                int newCol = coll + delCol[i];
                if(newRow >=0 && newCol >=0 && newRow < n && newCol <m && image[newRow][newCol] == initColor && res[newRow][newCol] != finalColor){
                    res[newRow][newCol] = finalColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int finalColor) {
        int initColor = image[sr][sc];
        vector<vector<int>> res = image;

        dfs(image, sr, sc, initColor, res, finalColor);
        return res;
    }
};

