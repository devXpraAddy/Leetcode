class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            while (j < k) {

                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    res.push_back(trip);
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};
