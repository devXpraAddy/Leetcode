class Solution {
public:
    bool countSub(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()){
            return true; // traversel complete so returning true
        }
        if(grid2[i][j] != 1){
            return true;
        }
        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);
        result = result & countSub(grid1, grid2, i, j-1);
        result = result & countSub(grid1, grid2, i, j+1);
        result = result & countSub(grid1, grid2, i+1, j);
        result = result & countSub(grid1, grid2, i-1, j);
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid2[i][j] == 1 && countSub(grid1, grid2, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};

