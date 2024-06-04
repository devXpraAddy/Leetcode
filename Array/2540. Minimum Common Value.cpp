//  https://leetcode.com/problems/minimum-common-value/description/

// Using Two Pointers
// T.C: O(m+n)
// S.C: O(1)
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        // int minVal1=0;
        // int minVal2=0;

        while (i < m && j < n)
        {
            if (nums1[i] == nums2[j])
            {
                // minVal1 = nums1[i];
                // minVal2 = nums2[j];
                return nums1[i];
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};
// Using Maps
// T.C= O(m+n)
// S.C = O(n)
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp.find(nums2[i]) != mp.end())
            { // checking if element if found in mp
                return nums2[i];
            }
        }
        return -1;
    }
};

// T.C : O(m+n)
// S.C : O(m)
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> st(begin(nums1), end(nums1));
        // it is similar to
        // Note: This syntax is only specific to unordered_set and not map

        // for(int i =0; i<nums1.size();i++){
        //      st.insert(nums1[i])
        //  }

        // or

        // unordered_set<int> st;
        //  st.insert(nums1.begin(), nums1.end());
        // or

        // unordered_set<int> st;
        //	for (int num : nums1) {
        //   st.insert(num);
        //	}

        for (int &num : nums2)
        {
            if (st.find(num) != st.end())
            {
                return num;
            }
        }

        return -1;
    }
};

// vector<pair<int, int>> keyValuePairs = {{1, 10}, {2, 20}, {3, 30}};
// unordered_map<int, int> mp;
// mp.insert(keyValuePairs.begin(), keyValuePairs.end());

// Using Binary Search
// T.C = O(mlogn)
// S.C = O(1)

class Solution
{
public:
    bool binarySearch(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2; // if we take l+r/2 then it will give TLE

            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }

    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (binarySearch(nums2, nums1[i]))
            {
                return nums1[i];
            }
        }
        return -1;
    }
};
