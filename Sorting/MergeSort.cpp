#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> arr, int left, int mid, int right)
{
}

void mergeSort(vector<int> arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    while (left < right)
    {

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 5, 13, 42, 2};
    mergeSort(arr, 0, arr.size() - 1);
    display(arr);
}