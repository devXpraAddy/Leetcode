class Solution {
public:
    int characterReplacement(string s, int k) {
        int i =0 ;
        int j =0;

        vector<int>mp(26, 0);
        int maxf = 0;
        int maxi = 0;

        while(j<s.size()){
            mp[s[j] - 'A']++;
            maxf = max(maxf, mp[s[j] - 'A']);

            while(j-i+1 - maxf > k){
                mp[s[i] - 'A']--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};