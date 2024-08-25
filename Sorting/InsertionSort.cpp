#include <bits/stdc++.h>

using namespace std;

class Solutions
{
public:
    void insertSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > temp)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
    }
    void display(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
    }
};

int main()
{
    vector<int> nums = {23, 1, 10, 5, 2};
    Solutions sol;
    sol.insertSort(nums);
    sol.display(nums);
}
