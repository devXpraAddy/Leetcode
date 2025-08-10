class Solution {
private:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(idx == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return 1e9+7;
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int take = 1e9 + 7;

        if(amount >= coins[idx]){
            take = 1 + solve(idx, coins, amount - coins[idx], dp);
        }
        int skip = solve(idx-1, coins, amount, dp);

        return dp[idx][amount] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int res = solve(n-1, coins, amount, dp);
        return res >= 1e9 ? -1 : res;
    }
};