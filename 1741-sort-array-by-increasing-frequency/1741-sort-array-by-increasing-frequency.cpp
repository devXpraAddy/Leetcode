class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int x: nums){
            mp[x]++;    
        }
        sort(nums.begin(), nums.end(), [&](int & a, int & b){
            if(mp[a] == mp[b]){
                return a>b; // sort in descending 
            }else{
                return mp[a] < mp[b]; // sort in ascending based on freq
            }
        });
        return nums;
    }
};