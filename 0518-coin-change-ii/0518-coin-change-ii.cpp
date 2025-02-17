class Solution {
public:
    int t[5001][301];
    int solve(vector<int>& coins, int amount, int i) {
        if (i == 0) {
            if (amount % coins[i] == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if(t[amount][i] != -1){
            return t[amount][i];
        }

        int skip = solve(coins, amount, i - 1);
        int take = 0;
        if (coins[i] <= amount) {
            take = solve(coins, amount - coins[i], i);
        }
        return t[amount][i] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        int n = coins.size();
        return solve(coins, amount, n - 1);
    }
};