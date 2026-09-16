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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and last node
        int len = 1;
        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        // Remove unnecessary rotations
        k = k % len;

        if (k == 0)
            return head;

        // Make circular
        temp->next = head;

        // Find new last node
        int steps = len - k;
        temp = head;

        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }

        // New head
        head = temp->next;

        // Break the circle
        temp->next = NULL;

        return head;
    }
};