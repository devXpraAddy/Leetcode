class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> res;
        for(int n: nums){
            mp[n]++;
        }
        int i =0;
        for(auto it: mp){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};