/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // Step 1: Find if cycle exists
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Step 2: Reset slow to head
                slow = head;

                // Move both one step at a time
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Cycle starting node
                return slow;
            }
        }

        // No cycle
        return NULL;
    }
};