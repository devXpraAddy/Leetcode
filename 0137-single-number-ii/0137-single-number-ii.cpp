class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int k = 0; k<32; k++){
            int cnt0 = 0;
            int cnt1 = 0;
            int temp = (1<<k);
            for(int num: nums){
                if((num & temp) == 0){
                    cnt0++;
                }else{
                    cnt1++;
                }
            }
            if(cnt1 % 3 == 1){
                res = (res | temp);
            }
        }
        return res;
    }
};
