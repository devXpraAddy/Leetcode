class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> mp(501,0);

        for(int i= 0;i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0;i<nums.size(); i++){
            if(mp[nums[i]] %2 != 0){
                return false;
            }
        }
        return true;
    }
};