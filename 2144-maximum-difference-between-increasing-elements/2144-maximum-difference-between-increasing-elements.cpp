class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = INT_MIN;

        for(int i =0 ;i<nums.size(); i++){
            for(int j = 0; j<nums.size(); j++){
                if(i<j && nums[i]< nums[j]){
                    maxi = max(maxi, nums[j]-nums[i]);
                }
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};