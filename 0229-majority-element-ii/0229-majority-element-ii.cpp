class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = NULL;
        int cnt1 = 0;

        int maj2 = NULL;
        int cnt2 = 0;

        for(int i =0; i<nums.size(); i++){
            if(maj1 == nums[i]){
                cnt1++;
            }else if(maj2 == nums[i]){
                cnt2++;
            }else if(cnt1 == 0){
                maj1 = nums[i];
                cnt1 =1;
            }else if(cnt2 == 0){
                maj2 = nums[i];
                cnt2 =1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;

        for(int& num: nums){
            if(maj1 == num){
                cnt1++;
            }else if(maj2 == num){
                cnt2++;
            }
        }
        if(cnt1 > floor(n/3)){
            res.push_back(maj1);
        }
        if(cnt2 > floor(n/3)){
            res.push_back(maj2);
        }
        return res;
    }
};