class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        // vector<int> dp(n + 1, -1);
        int prev = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++) {
            int one = prev;
            int two = prev2;
            
            int curr = one + two;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};