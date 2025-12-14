class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        int n = nums.size();

        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
  
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid -1]){
                return nums[mid];
            }
            //left half
            if((mid % 2 == 1 && nums[mid -1] == nums[mid]) || mid % 2 == 0 && nums[mid + 1] == nums[mid]){ //we are on the odd part and left of the odd and mid is same
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
};