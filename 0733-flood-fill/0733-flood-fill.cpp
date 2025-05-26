class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, int initColor, vector<vector<int>>& res, int finalColor){
        res[row][col] = finalColor;

        int n = image.size();
        int m = image[0].size();

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        for(int i = 0;i<4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if(newRow >=0 && newCol >=0 && newRow < n && newCol <m && image[newRow][newCol] == initColor && res[newRow][newCol] != finalColor){
                dfs(image, newRow, newCol, initColor, res, finalColor);
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

