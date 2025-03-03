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
        res.resize(nums.size());
        int j = 0;
        for(int i = 0;i<sml.size(); i++){
            res[j] = sml[i];
            j++;
        }
        for(int i = 0;i<eq.size(); i++){
            res[j] = eq[i];
            j++;
        }
        for(int i = 0;i<large.size(); i++){
            res[j] = large[i];
            j++;
        }

        return res;
    }
};