// https://leetcode.com/problems/coin-change-ii/description/

// Recursion
class Solution
{
public:
    int solve(vector<int> &coins, int idx, int amount)
    {
        if (idx == coins.size())
            return 0;
        if (amount == 0)
            return 1;

        if (amount < coins[idx])
        {
            return solve(coins, idx + 1, amount);
        }
        int skip = solve(coins, idx + 1, amount);
        int take = solve(coins, idx, amount - coins[idx]);
        return take + skip;
    }
    int change(int amount, vector<int> &coins)
    {
        return solve(coins, 0, amount);
    }
};

// Approach-1 (Recursion + Mempozation) : O(n*amount)
class Solution
{
public:
    int t[301][5001];
    int solve(vector<int> &coins, int idx, int amount)
    {
        if (idx == coins.size())
            return 0;
        if (amount == 0)
            return 1;

        if (t[idx][amount] != -1)
        {
            return t[idx][amount];
        }

        if (amount < coins[idx])
        {
            return t[idx][amount] = solve(coins, idx + 1, amount);
        }
        int skip = solve(coins, idx + 1, amount);
        int take = solve(coins, idx, amount - coins[idx]);
        return t[idx][amount] = take + skip;
    }
    int change(int amount, vector<int> &coins)
    {
        memset(t, -1, sizeof(t));
        return solve(coins, 0, amount);
    }
};

////Approach-2 (Bottom Up Version - 1)
class Solution
{
public:
    int combi(vector<int> &coins, int amount, int n)
    {
        vector<vector<int>> t(n + 1, vector<int>(amount + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (j == 0)
                {
                    t[i][j] = 1;
                }
                else if (i == 0)
                {
                    t[i][j] = 0;
                }
                else if (coins[i - 1] <= j)
                {
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][amount];
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        return combi(coins, amount, n);
    }
};

// Approach-3 (Bottom up Version - 2)
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<int> ways(amount + 1);
        // ways[i] = total # ways to get amount = i;
        // so, for amount = 0, we have one way {}
        ways[0] = 1;

        // take each coin one by one and see
        for (int i = 0; i < n; i++)
        {
            // I select a coin coins[i] and find # ways to get coins[i], coins[i]+1...until amount
            int curr_coin = coins[i];
            for (int j = curr_coin; j <= amount; j++)
            {
                int remain_amount = j - curr_coin; // Kis kis amount me tumne curr_coin add kara hoga to reach j

                // ways[remain_amount] = # ways to get amount "remain_amount"

                // ways[j] = # ways to get amount "j"
                ways[j] = ways[j] + ways[remain_amount];
            }
        }

        return ways[amount];
    }
};
