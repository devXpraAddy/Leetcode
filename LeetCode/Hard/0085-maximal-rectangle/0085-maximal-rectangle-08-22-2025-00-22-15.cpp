class Solution {
private:
    int largRecArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') { // always keep in mind if it's in char or int
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            // Calculate area after each row
            int area = largRecArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
