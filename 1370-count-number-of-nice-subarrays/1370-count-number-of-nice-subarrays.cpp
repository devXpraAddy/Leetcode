class Solution {
private:
    int solve(vector<int>& nums, int k) {
        // if (k < 0)
        //     return 0;
        int i = 0;
        int j = 0, n = nums.size();
        int sum = 0;
        int cnt = 0;

        while (j < n) {
            sum += nums[j] % 2;

            while (sum > k) {
                sum -= nums[i] % 2;
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};