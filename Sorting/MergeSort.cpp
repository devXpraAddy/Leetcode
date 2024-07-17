#include <bits/stdc++.h>

using namespace std;

// Function to merge two sorted halves of an array into a single sorted array
void merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;                    // Initial index for the left subarray
    int j = 0;                       // Initial index for the merged subarray
    int k = mid + 1;                 // Initial index for the right subarray
    vector<int> b(right - left + 1); // Temporary array to store merged result

    // Merge the two halves into the temporary array b
    while (i <= mid && k <= right)
    {
        if (arr[i] <= arr[k])
        {
            b[j++] = arr[i++]; // Add the smaller element to the temp array and move the index
        }
        else
        {
            b[j++] = arr[k++]; // Add the smaller element to the temp array and move the index
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid)
    {
        b[j++] = arr[i++]; // Add remaining elements from the left subarray to the temp array
    }

    // Copy remaining elements of right subarray, if any
    while (k <= right)
    {
        b[j++] = arr[k++]; // Add remaining elements from the right subarray to the temp array
    }

    // Copy the merged elements back into the original array arr
    int h = left;
    for (int i = 0; i < right - left + 1; i++)
    {
        arr[h++] = b[i]; // Copy the sorted elements from the temp array back to the original array
    }
}

// Function to implement merge sort on the array
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the midpoint of the array

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);      // Sort the left half
        mergeSort(arr, mid + 1, right); // Sort the right half

        // Merge the sorted halves
        merge(arr, left, mid, right); // Merge the two sorted halves
    }
}

// Utility function to print the elements of the array
void display(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 5, 13, 42, 2}; // Initialize the array
    mergeSort(arr, 0, arr.size() - 1);            // Perform merge sort on the array
    display(arr);                                 // Display the sorted array
    return 0;
}
