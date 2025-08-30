class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        string ans = "";
        for(int i =0 ;i<s.size(); i++){
            string word = "";
            while(i<n && s[i] != ' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.size() > 0){
                ans+=" "+ word;
            }
        }
        return ans.substr(1);
    }
};