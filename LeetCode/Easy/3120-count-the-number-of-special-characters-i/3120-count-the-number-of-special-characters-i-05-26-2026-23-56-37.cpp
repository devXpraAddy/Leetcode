class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> upper(26, 0);
        vector<bool> lower(26, 0);
        for (int i = 0; i < word.size(); i++){
            if (isupper(word[i])) upper[word[i]-'A'] = true;
            else lower[word[i]-'a'] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++){
            if (upper[i] && lower[i]) ans++;
        }
        return ans;
    }
};