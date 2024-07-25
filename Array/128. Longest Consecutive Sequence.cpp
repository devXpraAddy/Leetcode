// https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i] - 1) == mp.end())
            {
                int length = 1;
                int num = nums[i] + 1;
                while (mp.count(num))
                {
                    length++;
                    num++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
