// https://leetcode.com/problems/coin-change/description/

// recursion
class Solution
{
public:
    int solve(vector<int> &coins, int idx, int amount)
    {
        if (amount == 0)
            return 0;
        if (idx == coins.size())
            return INT_MAX - 1;
        int result = 0;
        if (coins[idx] > amount)
        {
            int skip = solve(coins, idx + 1, amount);
            result = skip;
        }
        else
        {
            int take = 1 + solve(coins, idx, amount - coins[idx]);
            int skip = solve(coins, idx + 1, amount);
            result = min(take, skip);
        }
        return result;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int result = solve(coins, 0, amount);
        return result == INT_MAX - 1 ? -1 : result;
    }
};

// recursion + memo

class Solution
{
public:
    int t[13][10001];
    int solve(vector<int> &coins, int idx, int amount)
    {
        if (amount == 0)
            return 0;
        if (idx == coins.size())
            return INT_MAX - 1;
        int result = 0;

        if (t[idx][amount] != -1)
        {
            return t[idx][amount];
        }

        if (coins[idx] > amount)
        {
            int skip = solve(coins, idx + 1, amount);
            result = skip;
        }
        else
        {
            int take = 1 + solve(coins, idx, amount - coins[idx]);
            int skip = solve(coins, idx + 1, amount);
            result = min(take, skip);
        }
        return t[idx][amount] = result;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memset(t, -1, sizeof(t));
        int result = solve(coins, 0, amount);
        return result == INT_MAX - 1 ? -1 : result;
    }
};
