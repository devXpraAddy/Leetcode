/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high){
        int i = low;
        int j = mid + 1;
        int k = 0;
        vector<int> res;

        while(i<=mid && j<=high){
            if(arr[i] < arr[j]){
                res.push_back(arr[i]);
                i++;
            }else{
                res.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            res.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            res.push_back(arr[j]);
            j++;
        }
        k = low;
        for(int i =0 ;i<res.size();i++){
            arr[k] = res[i];
            k++;
        }
    }
    vector<int> mergeSort(vector<int>& arr, int low, int high){
        if(low == high) return arr;
        int mid = low + (high- low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
        return arr;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        vector<int> arr;

        while(temp!= NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        int low = 0;
        int high = n-1;
        vector<int> res = mergeSort(arr, low, high);

        ListNode* dummy = new ListNode(res[0]);
        ListNode* curr = dummy;

        for(int i = 1; i<res.size(); i++){
            curr->next = new ListNode(res[i]);
            curr = curr->next;
        }
        return dummy;
    }
};