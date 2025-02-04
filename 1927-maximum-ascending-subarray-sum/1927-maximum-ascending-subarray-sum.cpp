//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;
        int sum = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            } else {
                maxSum = max(maxSum, sum); //60
                sum = nums[i]; //5
            }
        }

        return max(maxSum, sum);
    }
};



