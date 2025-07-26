class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int cnt =0;
        int maxi =0;
        
        while(i<n){
            if(nums[i] == 0){
                cnt =0;
                i++;
            }else{
                cnt++;
                i++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};