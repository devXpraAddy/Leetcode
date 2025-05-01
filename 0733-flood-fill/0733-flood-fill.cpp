class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, vector<vector<int>>& res, int newColor, int oldColor){
        res[sr][sc] = newColor;

        int n = image.size();
        int m = image[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1}; 

        for(int i = 0;i<4; i++){
                int nrow = sr + delRow[i];
                int ncol = sc + delCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow <n && ncol <m && image[nrow][ncol] == oldColor && res[nrow][ncol] != newColor){
                    dfs(image, nrow, ncol, res, newColor, oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image; // making a copy to not modify initial matrix
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, res, newColor, oldColor);
        return res;
    }
};

