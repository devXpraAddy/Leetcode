class Solution {
private:
    bool solve(int start, int end, string& s){
        if(start > end) return true;

        if(s[start] == s[end]){
            return solve(start + 1, end-1, s);
        }else{
            return false;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int sp = 0;

        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(solve(i, j, s) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};