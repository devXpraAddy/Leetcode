class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // No need to write base case in this
        // base case
        for (int idx = 0; idx < n; idx++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[idx][buy][0] = 0;
            }
        }
        // base case
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= k; cap++) {
                dp[n][buy][cap] = 0;
            }
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) { // no need to consider
                                                     // cap=0
                    int profit = 0;

                    if (buy) {
                        profit = max(-prices[idx] + dp[idx + 1][0][cap],
                                     0 + dp[idx + 1][1][cap]);
                    } else {
                        profit = max(prices[idx] + dp[idx + 1][1][cap - 1],
                                     0 + dp[idx + 1][0][cap]);
                    }
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
