class Solution {
private:
    bool isPossible(vector<int>&nums, int day, int m, int k){
        int cnt = 0;
        int noOfBuq = 0;

        for(int i =0;i<nums.size(); i++){
            if(nums[i]<= day){
                cnt++;
            }else{
                noOfBuq += (cnt/k);
                cnt = 0;
            }
        }
        noOfBuq += (cnt/k);
        return noOfBuq>=m;
    }
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
        }
        return mini;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int low = findMin(nums);
        int high = findMax(nums);

        // if(nums.size() < m*k) return -1;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, mid, m, k) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};