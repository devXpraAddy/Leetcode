class Solution {
public:
    int t[1001];
    int solve(int i, vector<int>& cost){
        if(i >= cost.size()) return 0;

        if(t[i] != -1){
            return t[i];
        }

        int a = cost[i] + solve(i+1, cost); // 1 jump
        int b = cost[i] + solve(i+2, cost); // 2 jump

        return t[i] = min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        return min(solve(0, cost), solve(1, cost));
    }
};
