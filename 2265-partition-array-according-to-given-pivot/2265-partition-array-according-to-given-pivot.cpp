class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        vector<int> sml;
        vector<int> large;
        vector<int> eq;
        
        for(int i =0;i<nums.size(); i++){
            if(nums[i] > pivot){
                large.push_back(nums[i]);
            }else if(nums[i] == pivot){
                eq.push_back(nums[i]);
            }else{
                sml.push_back(nums[i]);
            }
        }

        for(int i = 0;i<sml.size(); i++){
            res.push_back(sml[i]);
        }
        for(int i = 0;i<eq.size(); i++){
            res.push_back(eq[i]);
        }
        for(int i = 0;i<large.size(); i++){
            res.push_back(large[i]);
        }

        return res;
    }
};