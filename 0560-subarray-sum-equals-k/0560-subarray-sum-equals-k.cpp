class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int res=0;
        int sum =0;
        mp[0] = 1;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            int comp = sum - k;
            if(mp.find(comp) != mp.end()){
                res += mp[comp];
            }
            mp[sum]++;
        }
        return res;
    }
};