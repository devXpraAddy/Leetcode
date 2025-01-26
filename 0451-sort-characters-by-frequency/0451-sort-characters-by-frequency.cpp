class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};

        for(int i =0; i<s.size(); i++){
            // mp[s -'a']++; // this is done when we are using vector in place of map
            freq[s[i]]++;
        }
        sort(s.begin(), s.end(), [&](char & a, char &b){
            if(freq[a] == freq[b]){
                return a < b;
            }else{
                return freq[a] > freq[b];
            }
        });
        return s;
    }
};