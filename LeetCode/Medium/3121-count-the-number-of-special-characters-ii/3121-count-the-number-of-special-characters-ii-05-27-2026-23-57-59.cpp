class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int,int>>temp(26,{-1,-1});
                 
        for(int i=0;i<word.size();i++){
            char ch =word[i];
            if(ch>='a' && ch<='z'){
               temp[ch-'a'].first=i;
            }
            else{
                if(temp[ch-'A'].second==-1)temp[ch-'A'].second=i;
            }
        }

        int ans=0;

        for(int i=0;i<26;i++){
            int i1=temp[i].first;
            int i2=temp[i].second;
            if(i1!=-1 && i2!=-1 && i1<i2)ans++;
        }
        return ans;
      }
};