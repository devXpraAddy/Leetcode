// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// Recursion
class Solution
{
public:
    int solve(vector<int> prices, int day, int n, bool buy)
    {
        if (day >= n)
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            int take = solve(prices, day + 1, n, false) - prices[day]; // Profit   // if we have buyed it then next day we can't buy

            // solve(prices, day+1,n ,false); this gives us the selling price
            int not_take = solve(prices, day + 1, n, true);
            profit = max(take, not_take);
        }
        else
        {
            int sell = prices[day] + solve(prices, day + 2, n, true);
            int not_sell = solve(prices, day + 1, n, false);
            profit = max(sell, not_sell);
        }
        return profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy = true;
        int profit = solve(prices, 0, n, buy);
        return profit;
    }
};

// Recursion + memoization
#pragma GCC optimize("Ofast")

class Solution
{
public:
    int t[5000][2];
    int solve(vector<int> prices, int day, int n, bool buy)
    {
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
            int take = solve(prices, day + 1, n, false) - prices[day]; // Profit   // if we have buyed it then next day we can't buy

            // solve(prices, day+1,n ,false); this gives us the selling price
            int not_take = solve(prices, day + 1, n, true);
            profit = max({profit, take, not_take});
        }
        else
        {
            int sell = prices[day] + solve(prices, day + 2, n, true);
            int not_sell = solve(prices, day + 1, n, false);
            profit = max({profit, sell, not_sell});
        }
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = prices.size();
        memset(t, -1, sizeof(t));
        int buy = true;
        int profit = solve(prices, 0, n, buy);
        return profit;
    }
};