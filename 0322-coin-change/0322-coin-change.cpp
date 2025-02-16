class Solution {
public:
    int t[10001][13];
    int solve(vector<int>& coins, int amount, int i){
        if(i == 0){
            if(amount % coins[i] == 0){
                return amount / coins[i];
            }else{
                return 1e9;
            }
        }
        if(t[amount][i] != -1){
            return t[amount][i];
        }

        int skip = 0 + solve(coins, amount, i-1);
        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + solve(coins, amount - coins[i], i);
        }
        return t[amount][i] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        int res = solve(coins, amount, n-1);

        return res == 1e9 ? -1 : res;
    }
};
