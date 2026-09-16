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
    ListNode* partition(ListNode* head, int x) {

        // Dummy nodes for the two lists
        ListNode* smallDummy = new ListNode(0);
        ListNode* bigDummy = new ListNode(0);

        // Moving pointers
        ListNode* small = smallDummy;
        ListNode* big = bigDummy;

        // Traverse original list
        ListNode* curr = head;

        while (curr != NULL) {

            if (curr->val < x) {

                // Add node to small list
                small->next = curr;
                small = small->next;
            }
            else {

                // Add node to big list
                big->next = curr;
                big = big->next;
            }

            curr = curr->next;
        }

        // Connect small list to big list
        small->next = bigDummy->next;

        // End the list
        big->next = NULL;

        // Return the real head
        return smallDummy->next;
    }
};