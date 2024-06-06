// https://leetcode.com/problems/3sum/description/

class Solution
{
public:
    vector<vector<int>> result;
    void twosum(vector<int> &nums, int target, int i, int j)
    {
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                // removing duplicates from starting and ending
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
            else if (nums[i] + nums[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return {};
        }
        result.clear();
        sort(nums.begin(), nums.end());
        // fixing one element : n1
        for (int i = 0; i < n; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            { // removing duplicates
                continue;
            }

            int n1 = nums[i];
            int target = -n1;

            twosum(nums, target, i + 1, n - 1); // it will find n2 and n3 : {n1,n2,n3}
        }
        return result;
    }
};
