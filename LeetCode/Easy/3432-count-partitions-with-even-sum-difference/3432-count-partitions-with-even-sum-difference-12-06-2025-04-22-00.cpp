class Solution {
public:
    int countPartitions(vector<int>& nums) {
            int sum =0;
        int cnt =0;
        for(int i =0;i<nums.size(); i++){
            sum+= nums[i];
        }
        int leftsum =0 ;
        for(int i =0; i<nums.size()-1; i++){
            leftsum += nums[i];
            int rightsum = sum - leftsum;
            if((leftsum - rightsum)%2 == 0){
                cnt++;
            } 
        }
        return cnt;
    }
};