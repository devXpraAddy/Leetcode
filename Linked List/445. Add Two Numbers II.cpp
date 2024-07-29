// https://leetcode.com/problems/add-two-numbers-ii/description/

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
private:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *temp;
        while (curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        int carry = 0;
        while (l1 && l2)
        {
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            int digit = sum % 10;
            l3->next = new ListNode(digit);
            l3 = l3->next;
            l2 = l2->next;
            l1 = l1->next;
        }
        while (l1)
        {
            int sum = carry + l1->val;
            carry = sum / 10;
            int digit = sum % 10;
            l3->next = new ListNode(digit);
            l3 = l3->next;
            l1 = l1->next;
        }
        while (l2)
        {
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
        ListNode *result = reverse(head->next);
        delete (head);
        return result;
    }
};