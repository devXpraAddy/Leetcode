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
    ListNode* deleteMiddle(ListNode* head) {
        int n =0;
        ListNode* slow = head;
        while(slow != NULL){
            n++;
            slow = slow->next;
        }
        slow = head;

        if(n == 1) return NULL;
        if(n == 2){
            slow->next = NULL;
            return head;
        }

        int val = (n/2)-1;

        while(val--  > 0){
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow ->next = slow->next->next;
        delete(del);

        return head;
    }
};