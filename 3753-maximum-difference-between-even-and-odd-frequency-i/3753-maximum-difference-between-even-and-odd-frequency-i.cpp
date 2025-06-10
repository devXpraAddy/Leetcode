class Solution {
public:
    int maxDifference(string s) {

        unordered_map<char, int>mp;
        for(int i =0 ;i<s.size(); i++){
            mp[s[i]]++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for(auto it: mp){
            if(it.second %2 != 0){
                maxOdd = max(maxOdd, it.second);
            }else{
                minEven = min(minEven, it.second);
            }
        }
        return maxOdd - minEven;
    }
};