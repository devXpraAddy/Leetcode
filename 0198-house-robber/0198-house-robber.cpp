class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        // vector<int>dp(n, -1);
        int pre = nums[0];
        int pre2 = 0;

        for(int i =1;i<n; i++){
            int take = nums[i];
            if(i > 1){
                take = take + pre2;
            }
            int skip = 0 + pre;
            int curr = max(take, skip);
            pre2 = pre;
            pre = curr;
        }
        return pre;
    }
};
