// https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// Brute Force TLE
// T.C = O(n^2)
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        // Non-circular subarray
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        // Circular subarray
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += nums[(i + j) % n];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
// Using Kadane's Algorithm
// T.C = O(n)

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();

        int maxSum = nums[0];
        int currSum_max = nums[0];

        int minSum = nums[0];
        int currSum_min = nums[0];

        int totalSum = 0;

        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }

        for (int i = 1; i < n; i++)
        {
            currSum_max = max(nums[i], nums[i] + currSum_max);
            maxSum = max(maxSum, currSum_max);

            currSum_min = min(nums[i], nums[i] + currSum_min);
            minSum = min(minSum, currSum_min);
        }
        int cir_sum_sub = totalSum - minSum;
        if (maxSum > 0)
        {
            return max(maxSum, cir_sum_sub);
        }
        return maxSum;
    }
};

// Writing it separately
// T.C = O(n)

class Solution
{
public:
    int kadanesMax(vector<int> &nums, int n)
    {
        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int> &nums, int n)
    {
        int sum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);

        int minSum = kadanesMin(nums, n);

        int maxSum = kadanesMax(nums, n);

        int circSum = SUM - minSum;

        if (maxSum > 0)
        {
            return max(maxSum, circSum);
        }

        return maxSum;
    }
};
