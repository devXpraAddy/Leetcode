class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int maxCount = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);

            } else if (nums[i] == 0) {
                count = 0;
            }
            i++;
        }
        return maxCount;
    }
};