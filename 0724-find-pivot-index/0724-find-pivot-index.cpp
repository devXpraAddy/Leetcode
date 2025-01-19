class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumleft;
        int sumright;

        for(int i =0;i<nums.size(); i++){
            sumleft = 0;
            for(int j = 0; j<i; j++){
                sumleft+= nums[j];
            }
            sumright = 0;
            for(int j = i+1; j<nums.size(); j++){
                sumright += nums[j];
            }
            if(sumleft == sumright){
                return i;
            }
        }
        return -1;
    }
};