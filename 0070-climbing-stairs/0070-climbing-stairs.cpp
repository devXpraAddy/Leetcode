class Solution {
public:
    int t[46];
    int solve(int n ){
        if(n == 0) return 1;
        if(n == 1) return 1;

        if(t[n] != -1){
            return t[n];
        }

        int a = solve(n-1);
        int b = solve(n-2);
        return t[n] = a+b;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};