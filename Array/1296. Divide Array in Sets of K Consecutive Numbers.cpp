// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int n = nums.size();
        if (n % k != 0)
            return false;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        while (!mp.empty())
        {
            int curr = mp.begin()->first;

            for (int i = 0; i < k; i++)
            {
                if (mp[curr + i] == 0)
                {
                    return false;
                }
                mp[curr + i]--;
                if (mp[curr + i] < 1)
                {
                    mp.erase(curr + i);
                }
            }
        }
        return true;
    }
};

// same as https://leetcode.com/problems/hand-of-straights/description/