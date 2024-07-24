// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k)
            {
                return true;
            }
            // Update the index of nums[i] in the unordered_map
            // This ensures that the unordered_map always stores the most recent index of each element
            mp[nums[i]] = i;
        }
        return false;
    }
};