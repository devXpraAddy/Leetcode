class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int j = nums[i];
            int old = nums[j];

            // need to get the old num
            if(j < i){
                old = nums[j]/1000;
            }

            nums[i] *= 1000;
            nums[i] += old;
        }

        for(int i=0; i<nums.size(); i++){
            nums[i] %= 1000;
        }

        return nums;
    } 
};