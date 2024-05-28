// Problem link : https://leetcode.com/problems/two-sum

// Two pointer approach
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> numPairs;

        // Create a vector of pairs with the number and its index
        for (int i = 0; i < n; i++)
        {
            numPairs.push_back({nums[i], i});
        }

        // Sort the vector of pairs based on the number while preserving the index.
        sort(numPairs.begin(), numPairs.end());

        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            int sum = numPairs[i].first + numPairs[j].first;

            if (sum == target)
            {
                return {numPairs[i].second, numPairs[j].second};
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return {};
    }
};

// Easy 1 pass (better approach)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i}; // or you can return {i, mp[complement]}
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};

// Easy Two pass
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];
            if (mp.find(rem) != mp.end())
            {
                if (mp[rem] != i)
                    return {i, mp[rem]};
            }
        }
        return {-1, -1};
    }
};

// One-pass using count
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement))
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};
