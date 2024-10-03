class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> zero;
        vector<int> one;
        vector<int> two;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero.push_back(nums[i]);
            }
            if(nums[i] == 1){
                one.push_back(nums[i]);
            }
            if(nums[i] == 2){
                two.push_back(nums[i]);
            }
        }
        for(int i = 0; i<zero.size(); i++){
            ans.push_back(zero[i]);
        }
        for(int i = 0; i<one.size(); i++){
            ans.push_back(one[i]);
        }
        for(int i = 0; i<two.size(); i++){
            ans.push_back(two[i]);
        }
        for(int i = 0; i<ans.size(); i++){
            nums[i] = ans[i];
        }
    }
};