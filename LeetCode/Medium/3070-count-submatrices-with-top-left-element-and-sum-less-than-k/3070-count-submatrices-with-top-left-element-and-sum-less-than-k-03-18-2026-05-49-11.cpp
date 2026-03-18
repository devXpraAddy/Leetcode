class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;

        // For eg - 7 6 3    becomes  7 13 16  after prefix sum
        //          6 6 1             13 25 29
        
        //Think it like prefix sum you just need to add prev. sum to next element 
        //For rows
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        // Here
        // 7 13 16
        // 6 12 13

        //For columns
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        // Now
        // 7 13 16
        // 13 25 29
        

        //In the end we count the elements which are having sum less than or equal to k
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<=k)
                    ans++;
            }
        }
        return ans;
        
    }
};