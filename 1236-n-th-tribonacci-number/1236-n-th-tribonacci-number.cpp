class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        // vector<int>dp(n+1, -1);
        int prev3 =0;
        int prev2 =1;
        int prev =1;

        for(int i = 3; i<=n; i++){
            int a = prev;
            int b = prev2;
            int c = prev3;

            int curr = a+b+c;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};