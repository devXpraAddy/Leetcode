class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i= 0; i<n+1; i++){
            long long cnt = 0;
            int num = i;
            while(num>0){
                num = num & (num-1);
                cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};