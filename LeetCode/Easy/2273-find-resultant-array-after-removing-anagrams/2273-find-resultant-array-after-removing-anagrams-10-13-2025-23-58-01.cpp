class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            vector<int> freq1(26, 0), freq2(26, 0);
            
            for (char ch : res.back()) {
                freq1[ch - 'a']++;
            }
            for (char ch : words[i]) {
                freq2[ch - 'a']++;
            }
            
            if (freq1 != freq2) {
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
};