// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Brute Force
//  T.C = O(n)
//  S.C = O(n)
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                result.push_back(it.first);
            }
        }
        return result;
    }
};
// Optimal Approach (using no. as index appraoch) for range [1--n]
// T.C = O(n)
// S.C = O(1)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int val = abs(nums[i]);
            int idx = num - 1;

            if (nums[idx] < 0)
            {
                result.push_back(val);
            }
            else
            {
                nums[idx] *= -1;
            }
        }
        return result;
    }
};
// Using sorting
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
