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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            mp[curr->val]++;
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        prev = dummy;
        curr= head;

        while(curr){
            if(mp[curr->val] > 1){
                prev->next = curr->next;
            }else{
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};