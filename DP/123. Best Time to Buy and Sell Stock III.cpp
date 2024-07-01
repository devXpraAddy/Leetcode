// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution
{
public:
    int solve(int i, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int limit)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (limit == 0)
        {
            return 0;
        }
        if (dp[i][buy][limit] != -1)
        {
            return dp[i][buy][limit];
        }
        int profit = 0;
        if (buy)
        { // when buy=1                      //buy        //skip
            profit = max((-prices[i] + solve(i + 1, 0, prices, dp, limit)), (0 + solve(i + 1, 1, prices, dp, limit)));
        }
        else
        { // when buy=0                      // sell               // skip
            profit = max((prices[i] + solve(i + 1, 1, prices, dp, limit - 1)), (0, solve(i + 1, 0, prices, dp, limit)));
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(); // 2 is the dim of buy and 3 is of limit
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices, dp, 2);
    }
};
