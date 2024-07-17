#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a= *b;
    *b= temp;
}

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int i = start;
    
    for(int j = start+1; j<=end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[start]);
    return i;
}

void Quicksort(int arr[], int start, int end){
    if(start >= end){
        return ;
    }
    int k = partition(arr, start, end);
    Quicksort(arr, start, k-1);
    Quicksort(arr, k+1, end);
}

void printarr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<< arr[i];
    }
    cout<<endl;
}

int main(){
    vector<int>arr = {2,4,2,6,72,1,3,5};
    printarr(arr,n);
    Quicksort(arr, 0, n-1);
    Quicksort(arr,n);
}
