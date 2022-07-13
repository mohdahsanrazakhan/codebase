/*
 * TC: O(N)
 * SC: O(1)
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *start = new ListNode(); // Creating a dummy node
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        // fast pointer iterate 'n' times
        for (int i = 1; i <= n; ++i)
            fast = fast->next;

        // move fast and slow pointer together till fast's next not reach to NULL
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Once fast's next reaches the NULL then
        slow->next = slow->next->next;

        // Dummy next node will be new head of that linked list
        return start->next;
    }
};