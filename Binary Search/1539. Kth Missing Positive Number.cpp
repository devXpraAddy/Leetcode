// https://leetcode.com/problems/kth-missing-positive-number/description/

// Brute force 1
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        set<int> st;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            st.insert(arr[i]);
        }
        for (int i = 1; i < 1000 + 1001; i++)
        {
            if (st.find(i) == st.end())
            {
                k--;
            }
            if (k == 0)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
// Brute force 2
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 0;
        int num = 1;
        int n = arr.size();
        while (k > 0 && i < n)
        {
            if (arr[i] == num)
            {
                i++;
                num++;
            }
            else
            {
                k--;
                num++;
            }
        }
        // case when no duplicate found
        //{1,2,3}, k=2
        // num = 3
        // num = 4 extra  k--
        // num = 5  extra  k--

        while (k > 0)
        {
            num++; // by this one num will be incremented extra
            k--;
        }
        return num - 1;
    }
};

// brute force 3
// T.C = O(n)
// S.C = O(1)
int missingK(vector<int> vec, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (vec[i] <= k)
            k++; // shifting k
        else
            break;
    }
    return k;
}

// using binary search
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int count_of_missing = arr[mid] - (mid + 1);

            if (count_of_missing < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left + k;
    }
};
