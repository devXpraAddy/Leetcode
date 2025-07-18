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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < lists.size(); i++) { // klogk(k : size)
            if (lists[i] != NULL) {
                pq.push({lists[i]->val, lists[i]}); // logk
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) { // K*N * 3*logk
            pair<int, ListNode*> p = pq.top();
            temp->next = p.second;
            pq.pop(); // once we have deleted we want that the next should go in
                      // pq

            if (p.second->next != NULL) {
                pq.push({p.second->next->val, p.second->next});
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};