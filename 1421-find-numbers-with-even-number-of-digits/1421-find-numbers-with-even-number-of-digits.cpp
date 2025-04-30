class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        long long cnt1;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            cnt1=0;
            while (nums[i] > 0) {
                nums[i] = nums[i] / 10;
                cnt1++;
            }
            if (cnt1 % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};