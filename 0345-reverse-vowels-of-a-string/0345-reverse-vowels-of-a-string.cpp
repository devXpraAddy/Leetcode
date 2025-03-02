class Solution {
public:
    bool isVowal(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (isVowal(s[i]) && isVowal(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isVowal(s[i]) && !isVowal(s[j])) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};