class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int res = 0;
        mp[0] = 1;

        for(int i =0;i<n; i++){
            sum += nums[i];
            int comp = sum - k;
            if(mp.find(comp) != mp.end()){
                res+= mp[comp];
            }
            mp[sum]++;
        }
        return res;
    }
};