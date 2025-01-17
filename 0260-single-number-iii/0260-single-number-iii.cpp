class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n: nums){
            mp[n]++;
        }
        int j =0;
        for(int i = 0; i<nums.size(); i++){
            if(mp[nums[i]] == 1){
                nums[j] = nums[i];
                j++;
            }
        }
        nums.resize(j);
        return nums;
    }
};