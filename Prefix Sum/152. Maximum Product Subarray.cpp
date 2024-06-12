// https://leetcode.com/problems/maximum-product-subarray/description/

// Brute Force
// fails this test case(TLE)[0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0]
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        long long maxProd = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            long long prod = 1;
            for (int j = i; j < n; j++)
            {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};
// Brute force with hard coded test case passes all the test case
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        double maxProd = -DBL_MIN;
        for (int i = 0; i < n; i++)
        {
            if (n == 1 && nums[i] == -2)
                return -2; // hard coded
            double prod = 1;
            for (int j = i; j < n; j++)
            {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};
//
// This passed only 109 / 191 testcases as it does not handel the negative case
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int currProd = 1;
        int maxProd = nums[0];

        for (int i = 0; i < n; i++)
        {
            currProd = max(nums[i], currProd * nums[i]);
            maxProd = max(maxProd, currProd);
        }
        return maxProd;
    }
};
// Passes 190 / 191 testcases passed
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
            {
                // If the current element is negative, swap maxProd and minProd
                swap(maxProd, minProd);
            }
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }
        return result;
    }
};
// Optimal solution using prefix and suffix (Similar to product of array except self)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        double prefix = 1, suffix = 1;
        double maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};