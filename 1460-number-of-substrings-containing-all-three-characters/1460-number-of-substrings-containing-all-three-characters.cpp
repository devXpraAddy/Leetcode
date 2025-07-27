class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0 ;
        int j =0 ;
        int count =0 ;
        int n =s.size();
        vector<int>mp(3 , 0);

        while(j < n){
            mp[s[j]-'a']++;

            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                count += (n-j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};