// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        int carry = 0;
        ListNode *head = l3;
        while (l1 && l2)
        {
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            int digit = sum % 10;
            l3->next = new ListNode(digit);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        { // if l1 has greater length
            int sum = carry + l1->val;
            carry = sum / 10;
            int digit = sum % 10;
            l3->next = new ListNode(digit);
            l3 = l3->next;
            l1 = l1->next;
        }
        while (l2)
        { // if l2 has greater length
            int sum = carry + l2->val;
            carry = sum / 10;
            int digit = sum % 10;
            l3->next = new ListNode(digit);
            l3 = l3->next;
            l2 = l2->next;
        }
        if (carry)
        {
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};