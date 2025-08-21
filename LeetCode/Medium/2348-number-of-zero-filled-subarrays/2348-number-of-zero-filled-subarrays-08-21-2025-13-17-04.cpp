class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, n = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0){
                n++;
            }else {
                cnt += (n * (n + 1)) / 2;
                n = 0;
            }
        }
        if (n > 0) {
            cnt += (n * (n + 1)) / 2;
        }
        return cnt;
    }
};