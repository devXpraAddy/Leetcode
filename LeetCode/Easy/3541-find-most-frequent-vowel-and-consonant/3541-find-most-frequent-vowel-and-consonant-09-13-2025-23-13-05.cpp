class Solution {
private:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'){
            return true;
        }
        return false;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int>mp;

        for(int i =0;i<s.size(); i++){
            mp[s[i]]++;
        }
        int vow = 0;
        int cos = 0;

        for(int i=0;i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(isVowel(s[i])){
                    vow = max(vow, mp[s[i]]);
                }else{
                    cos = max(cos, mp[s[i]]);
                }
            }
        }
        return vow + cos;
    }
};