class Solution {
public:
    string reverseWords(string s) {
        string result = "", word = "";
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!word.empty()) {
                    result = word + " " + result;
                    word = "";
                }
            }else{
                word += s[i];
            }
        }
        return result.substr(0, result.size()-1);
    }
};