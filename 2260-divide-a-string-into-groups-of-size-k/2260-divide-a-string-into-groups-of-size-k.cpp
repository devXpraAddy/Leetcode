class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        string str = "";
        vector<string> res;
        int cnt = 0;

        for(int i =0 ;i<n; i++){
            cnt++;
            str+= s[i];
            if(cnt == k){
                res.push_back(str);
                cnt = 0;
                str = "";
            }
        }
        if(cnt == 0){
            return res;
        }
        int val = k - cnt;
        while(val != 0){
            str+=fill;
            val--;
        }
        res.push_back(str);
        return res;
    }
};