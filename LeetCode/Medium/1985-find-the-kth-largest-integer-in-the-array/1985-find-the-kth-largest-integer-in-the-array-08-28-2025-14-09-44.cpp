class Solution {

    struct comp{
        auto operator()(string &a, string &b){
            if(a.size() == b.size()){
                return a > b;
            }
            return a.size() > b.size(); // for min heap (opposite of array)
        }
    };

public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();

        priority_queue<string, vector<string>, comp>pq;

        for(int i =0;i<n; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
