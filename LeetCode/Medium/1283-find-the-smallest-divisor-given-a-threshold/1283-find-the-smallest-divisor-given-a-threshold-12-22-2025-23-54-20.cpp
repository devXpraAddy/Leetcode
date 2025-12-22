class Solution {
private:
    int solve(vector<int>&nums, int div){
        int total = 0;

        for(int i =0;i<nums.size(); i++){
            total += ceil((double)nums[i]/div);
        }
        return total;
    }
    int findMax(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i =0;i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(solve(nums, mid) <= threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};