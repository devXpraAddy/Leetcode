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
    ListNode* mergeTwoList(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(left != NULL && right != NULL){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if(left != NULL){
            curr->next = left;
        }
        if(right != NULL){
            curr->next = right;
        }
        return dummy->next;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL; // as we want to seperate 2 LL

        left = sortList(left);
        right = sortList(right);

        return mergeTwoList(left, right);
    }
};