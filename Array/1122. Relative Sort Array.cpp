// https://leetcode.com/problems/relative-sort-array/description/

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> mp;

        for (auto &nums : arr1)
        {
            mp[nums]++;
        }
        int i = 0;
        for (auto &nums : arr2)
        {
            while (mp[nums]-- > 0)
            {
                arr1[i++] = nums;
            }
        }
        for (auto it : mp)
        {
            int freq = it.second;
            if (freq > 0)
            {
                arr1[i++] = it.first;
                freq--;
            }
        }
        return arr1;
    }
};
