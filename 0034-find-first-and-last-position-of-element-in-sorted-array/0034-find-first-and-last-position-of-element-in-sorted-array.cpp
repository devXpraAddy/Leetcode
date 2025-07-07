class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sIdx = -1, eIdx = -1;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i] == target){
                sIdx = i;
                break;
            }
        }
        for(int i = n-1; i>=0 ; i--){
            if(nums[i] == target){
                eIdx = i;
                break;
            }
        }
        return {sIdx, eIdx};
    }
};