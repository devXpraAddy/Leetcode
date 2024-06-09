// https://leetcode.com/problems/subarray-sum-equals-k/

// Brute force
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int start = 0; start < n; start++)
        {
            for (int end = start; end < n; end++)
            {
                int sum = 0;
                for (int j = start; j <= end; j++)
                {
                    sum += nums[j];
                }
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Two for loops
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int start = 0; start < n; start++)
        {
            int sum = 0;
            for (int j = start; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Used similar approach to 2SUM
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        int currSum = 0;
        mp[0] = 1; // it has seen currSum = 0 once

        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            int complement = currSum - k;
            if (mp.find(complement) != mp.end())
            {
                count += mp[complement];
            }
            mp[currSum]++;
        }
        return count;
    }
};

// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int result = 0;
        int cumSum = 0;
        map<int, int> mp;
        mp.insert({0, 1}); // inserting 0 to consider the edge case
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            cumSum += nums[i];

            if (mp.count(sum - k)) // O(1)
                result += mp[cumSum - k];

            mp[cumSum]++;
        }
        return result;
    }
};

