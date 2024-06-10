// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

// Brute Force (TLE)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
// Using Kadane's Algorithm
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
