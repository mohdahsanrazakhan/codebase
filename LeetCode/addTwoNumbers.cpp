/*
 * LeetCode: 2. Add Two Numbers
 * TC: O(n)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = NULL;
        ListNode *temp, *prev = NULL;
        int carry = 0, sum;

        // while l1 and l2 not equal to NULL
        while (l1 || l2)
        {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0); // if l1 and l2 present than l1->val and l2->val otherwise 0
            carry = (sum >= 10) ? 1 : 0;                           // if sum is greater than 10 then carry stores 1 otherwise 0
            sum = sum % 10;                                        // if sum is greater than 10, sum store unit digit.
            temp = new ListNode(sum);                              // create a new Node with sum as data
            if (result == NULL)                                    // if result is first node then set as head.
                result = temp;
            else
                prev->next = temp; // if result is not a first node then connect it to next.
            prev = temp;           // prev points on temp;

            // move l1 and l2 pointers to next node.
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
            temp->next = new ListNode(carry); // temp next create new node and store carry data.
        return result;
    }
};