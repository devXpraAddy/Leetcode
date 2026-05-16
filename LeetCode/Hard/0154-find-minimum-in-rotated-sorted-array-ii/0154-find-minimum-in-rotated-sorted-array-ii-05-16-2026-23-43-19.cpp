class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;

        int mini = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){ //handling duplicate
                mini = min(mini, nums[low]);
                low = low + 1;
                high = high -1;
                continue;
            }
            
            if(nums[low] <= nums[mid]){
                //left
                mini = min(mini, nums[low]);
                low = mid + 1;
            }else{
                //right
                mini = min(mini, nums[mid]);
                high = mid -1;
            }
        }
        return mini;
    }
};