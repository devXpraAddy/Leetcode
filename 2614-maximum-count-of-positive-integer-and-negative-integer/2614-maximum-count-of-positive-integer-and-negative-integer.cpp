class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntP = 0;
        int cntN = 0;
        int MAXI = INT_MIN;

        for(int i =0;i<nums.size(); i++){
            if(nums[i] >0){
                cntP++;
            }else if(nums[i] <0){
                cntN++;
            }
        }
        return max(cntP, cntN);
    }
};