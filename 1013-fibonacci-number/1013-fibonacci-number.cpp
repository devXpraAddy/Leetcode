class Solution {
private:
    int solve(int n ){
        if(n == 0) return 0;
        if(n == 1) return 1;

        int left = solve(n-1);
        int right = solve(n-2);

        return left + right;
    }
public:
    int fib(int n) {
        return solve(n);
    }
};