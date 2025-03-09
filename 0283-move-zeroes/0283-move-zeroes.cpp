class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;

        for(int i = 0;i<nums.size(); i++){
            if(nums[i] != 0){
                arr.push_back(nums[i]);
            }
        }
        for(int i =0;i<nums.size(); i++){
            if(nums[i] == 0){
                arr.push_back(nums[i]);
            }
        }
        int j =0;
        for(int i = 0; i<arr.size(); i++){
            nums[j] = arr[i];
            j++;
        }
    }
};