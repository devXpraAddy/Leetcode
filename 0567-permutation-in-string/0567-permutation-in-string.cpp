class Solution {
public:
    bool allzero(vector<int> & cnt){
        for(int i= 0; i<cnt.size(); i++){
            if(cnt[i] != 0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int k = s1.size();

        vector<int> cnt(26,0);

        for(int i = 0; i<s1.size(); i++){
            cnt[s1[i]- 'a']++;
        }
        int i = 0;
        int j = 0;
        while(j<n){
            cnt[s2[j] - 'a']--;
            if(j-i+1 == k){
                if(allzero(cnt)){
                    return true;
                }
                cnt[s2[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};