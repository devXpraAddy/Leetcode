class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
        vector<int> charr(26,0);

        for (int i = 0; i < n; i++) {
            charr[s1[i]-'a']++;
            if (s1[i] != s2[i]) {
                cnt++;
            }
        }

        for (char& ch : s2) {
            if (charr[ch-'a']==0) {
                return false;
            }
            charr[ch-'a']--;
        }

        if (cnt == 0 || cnt == 2)
            return true;
        return false;
    }
};