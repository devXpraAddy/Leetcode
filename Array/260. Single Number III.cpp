// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

// Using Unordered map
//  [T(n) = S(n) = O(n)]

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]] == 1)
            {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};

// Using Unordered set
//  [T(n) = S(n) = O(n)]

vector<int> singleNumber(vector<int> &nums)
{
    unordered_set<int> visited;
    // store num with odd freq into set
    for (auto &num : nums)
        if (visited.count(num))
            visited.erase(num);
        else
            visited.insert(num);
    // return ans
    return vector<int>(visited.begin(), visited.end());
}

// Using Sorting
// [T(n) = O(nlgn) and S(n) = O(1), excluding S(n) for std::sort()]

vector<int> singleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0, n = nums.size();
    while (i < n - 1)
        // skip equal elements
        if (nums[i] == nums[i + 1])
            i += 2;
        // generate ans
        else
        {
            ans.push_back(nums[i++]);
            if (ans.size() == 2)
                return ans;
        }
    // corner case
    if (ans.size() == 1)
        ans.push_back(nums.back());
    return ans;
}

// Using Bit Manipulation
// [T(n) = O(n) and S(n) = O(1)]

vector<int> singleNumber(vector<int> &nums)
{
    int firstXorSec = 0, mask = 1, first = 0;
    // get xor of first and sec
    for (auto &num : nums)
        firstXorSec ^= num;
    // get rightmost set bit in above xor
    while (not(firstXorSec & mask))
        mask <<= 1;
    // get first distinct number
    for (auto &num : nums)
        if (num & mask)
            first ^= num;
    // return ans
    return {first, firstXorSec ^ first};
}
