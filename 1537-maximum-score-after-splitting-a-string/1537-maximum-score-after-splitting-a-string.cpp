class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        int result = INT_MIN;
        
        for(int i = 0; i <=n-2; i++) { 
            
            int zeros_left = 0;
            for(int j = 0; j <= i; j++) {
                if(s[j] == '0') {
                    zeros_left++;
                }
            }
            
            int ones_right = 0;
            for(int j = i+1; j < n; j++) {
                if(s[j] == '1') {
                    ones_right++;
                }
            }
            
            result = max(result, zeros_left + ones_right);
            
        }
        
        return result;
    }
};
//T.C : O(n^2)
//S.C : O(1)