class Solution {
private:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, n = nums.size();
        int cnt = 0;

        while (j < n) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};