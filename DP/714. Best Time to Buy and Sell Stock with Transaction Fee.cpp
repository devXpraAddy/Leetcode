// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// This is giving TLE (41/44) test case passed
class Solution
{
public:
    int FEE;
    int solve(vector<int> &prices, int day, int n, bool buy,
              vector<vector<int>> &t)
    { // this
        if (day >= n)
        {
            return 0;
        }
        if (t[day][buy] != -1)
        {
            return t[day][buy];
        }
        int profit = 0;
        if (buy)
        {
            // buy
            int consider = solve(prices, day + 1, n, false, t) -
                           prices[day]; // profit // if we have buyed it then
                                        // next day we can't buy
            int not_consider = solve(prices, day + 1, n, true, t);
            profit = max({profit, consider, not_consider});
        }
        else
        {
            // sell
            int consider = solve(prices, day + 1, n, true, t) + prices[day] -
                           FEE; // if we have sold then we can buy it on day+1
            int not_consider =
                solve(prices, day + 1, n,
                      false, t); // this is false as we have to sell it and not buy
            profit = max({profit, consider, not_consider});
        }
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        FEE = fee;
        int n = prices.size();
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>> t(n, vector<int>(2, -1));

        int buy = true;
        int profit = solve(prices, 0, n, buy, t);
        return profit;
    }
};

// Passes all the test case
class Solution
{
public:
    int stock(vector<int> &v, int buy, int index, vector<vector<int>> &dp, int fee)
    {
        if (index == v.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        int profit = 0;

        if (buy)
        {

            int not_buy = stock(v, 1, index + 1, dp, fee);
            int buy = -v[index] + stock(v, 0, index + 1, dp, fee);
            profit = max(buy, not_buy);
        }
        else
        {

            int sell = v[index] - fee + stock(v, 1, index + 1, dp, fee);
            int not_sell = stock(v, 0, index + 1, dp, fee);
            profit = max(sell, not_sell);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return stock(prices, 1, 0, dp, fee);
    }
};