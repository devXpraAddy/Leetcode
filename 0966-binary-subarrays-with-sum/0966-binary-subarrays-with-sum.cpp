class Solution {
private:
    int solve(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int i =0;
        int j =0 ;
        int cnt =0;
        int sum =0;

        while(j<nums.size()){
            sum += nums[j];

            while(sum > goal){
                sum -= nums[i];
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};