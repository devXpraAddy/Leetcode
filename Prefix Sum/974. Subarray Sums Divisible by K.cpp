//  https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

// Brute force 1
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        // Iterate over all possible starting points
        for (int start = 0; start < n; ++start)
        {
            // Iterate over all possible ending points
            for (int end = start; end < n; ++end)
            {
                int sum = 0;
                // Calculate the sum of the subarray nums[start...end]
                for (int i = start; i <= end; ++i)
                {
                    sum += nums[i];
                }
                // Check if the sum is divisible by k
                if (sum % k == 0)
                {
                    ++count;
                }
            }
        }

        return count;
    }
};

// Brute force (TLE 70/73 test case)
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j]; // finding cumulative sum
                if (sum % k == 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Using map + prefix sum
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = 1;

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int rem = sum % k;

            if (rem < 0)
            {
                rem += k;
            }

            if (mp.find(rem) != mp.end())
            {
                result += mp[rem];
            }

            mp[rem]++;
        }

        return result;
    }
};
