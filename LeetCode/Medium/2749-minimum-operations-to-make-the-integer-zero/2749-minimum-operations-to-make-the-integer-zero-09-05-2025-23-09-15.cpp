class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 36; k++) {
            long long diff = num1 - 1LL * k * num2;
            if (__builtin_popcountll(diff) <= k && k <= diff)
                return k;
        }
        
        return -1;
    }
};