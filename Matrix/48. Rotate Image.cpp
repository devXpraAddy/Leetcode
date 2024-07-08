// https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size(); // since row and columns are same we can take only row

        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < col; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Other solution
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size();

        // find transpose
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // flip horizontally - For clock wise rotation
        for (int i = 0; i < N; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        /*
        //flip vertically - For anticlock wise rotation
        for(int col = 0; col<N; col++) {
            int row = 0;
            int mid = n/2;
            while(row < mid) {
                swap(matrix[row][col], matrix[n-row-1][col]);
                row++;
            }
        }
        */
    }
};