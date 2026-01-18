class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sums
        vector<vector<long long>> rowPrefix(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colPrefix(m + 1, vector<long long>(n, 0));

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPrefix[i][j + 1] = rowPrefix[i][j] + grid[i][j];
                colPrefix[i + 1][j] = colPrefix[i][j] + grid[i][j];
            }
        }

        int maxSize = min(m, n);

        // Try from largest size to smallest
        for (int k = maxSize; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    // Target sum = first row
                    long long target = rowPrefix[i][j + k] - rowPrefix[i][j];
                    bool isMagic = true;

                    // Check all rows
                    for (int r = i; r < i + k && isMagic; r++) {
                        long long rowSum =
                            rowPrefix[r][j + k] - rowPrefix[r][j];
                        if (rowSum != target)
                            isMagic = false;
                    }

                    // Check all columns
                    for (int c = j; c < j + k && isMagic; c++) {
                        long long colSum =
                            colPrefix[i + k][c] - colPrefix[i][c];
                        if (colSum != target)
                            isMagic = false;
                    }

                    // Check diagonals
                    long long diag1 = 0, diag2 = 0;
                    for (int d = 0; d < k; d++) {
                        diag1 += grid[i + d][j + d];
                        diag2 += grid[i + d][j + k - 1 - d];
                    }

                    if (diag1 != target || diag2 != target)
                        isMagic = false;

                    if (isMagic)
                        return k;
                }
            }
        }

        
        return 1;
    }
};