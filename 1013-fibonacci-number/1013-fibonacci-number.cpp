class Solution {
public:
    int fib(int n) {
        if(n== 0) return 0; // Don't forget this edge case
        // vector<int>dp(n+1, -1);
        int prev2 = 0;
        int prev = 1;

        for(int i =2; i<=n; i++){
            int left = prev;
            int right = prev2;

            int curr = left + right;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};