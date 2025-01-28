class Solution {
public:
    bool allzero(vector<int> & cnt){
        for(int i = 0; i<cnt.size(); i++){
            if(cnt[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> cnt(26, 0);
        for(int i = 0; i<p.size(); i++){
            cnt[p[i] - 'a']++;
        }
        vector<int> res;
        int i = 0, j = 0;

        while(j<n){
            cnt[s[j] - 'a']--;
            if(j-i+1 == k){
                if(allzero(cnt)){
                    res.push_back(i);
                }
                cnt[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};