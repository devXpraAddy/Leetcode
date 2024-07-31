// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

// Two pass solution
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int count = 0;
        ListNode *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int result = count - n;

        if (n == count)
            return head->next;
        temp = head;
        ListNode *prev = NULL;

        while (result--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete (temp);

        return head;
    }
};

// One pass solution

// Approach-2 (1 Pass)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            return head->next;
        }

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete (temp);
        return head;
    }
};
