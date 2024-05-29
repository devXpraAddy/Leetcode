// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> x, y;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        for (int i = 0; i < x.size(); i++)
        {
            int index = x[i];
            for (int j = 0; j < n; j++)
            {
                matrix[index][j] = 0;
            }
        }
        for (int i = 0; i < y.size(); i++)
        {
            int index = y[i];
            for (int j = 0; j < m; j++)
            {
                matrix[j][index] = 0;
            }
        }
    }
};
// alternate approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
