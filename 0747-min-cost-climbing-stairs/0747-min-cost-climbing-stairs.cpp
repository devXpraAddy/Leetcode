class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        // vector<int>dp(n+1, -1);

        int prev2 = cost[0];
        int prev = cost[1];

        for(int i =2; i<n; i++){
            int left = cost[i] + prev;
            int right = cost[i] + prev2;

            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }

        return min(prev, prev2);
    }
};