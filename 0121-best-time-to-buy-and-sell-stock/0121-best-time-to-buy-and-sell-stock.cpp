class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int mini = prices[0];
        int maxi = INT_MIN;

        for(int i= 0; i<prices.size(); i++){
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }
        return maxi;
    }
};