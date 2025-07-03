class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size() < k){
            string temp = s;
            for(int i = 0;i<temp.size(); i++){
                char str = temp[i]+1;
                s+=str;
            }
        }
        for(int i =0 ; i<s.size(); i++){
            if(i == k-1){
                return s[i];
            }
        }
        return '-1';
    }
};