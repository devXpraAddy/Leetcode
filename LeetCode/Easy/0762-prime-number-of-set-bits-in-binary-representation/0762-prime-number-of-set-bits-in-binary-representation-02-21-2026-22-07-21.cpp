class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        while (L <= R) {
            int b = __builtin_popcount(L++);
            count += b < 4 ? b > 1 : b % 2 && b % 3;
        }
        return count;
    }
};