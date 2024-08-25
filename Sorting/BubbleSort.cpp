#include <bits/stdc++.h>

using namespace std;

class Solutions
{
public:
    vector<int> bubbleSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n - i; j++)
            {
                if (nums[j] < nums[j - 1])
                {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }
        return nums;
    }
    void display(vector<int> &result)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
};

int main()
{
    vector<int> nums = {15, 16, 6, 8, 5};
    Solutions sol;
    vector<int> result = sol.bubbleSort(nums);
    sol.display(result);
}
