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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Tortoise: 1 step
            fast = fast->next->next;     // Hare: 2 steps

            if (slow == fast) {
                return true;             // Cycle found
            }
        }

        return false;                    // No cycle
    }
};