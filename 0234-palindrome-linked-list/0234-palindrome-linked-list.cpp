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
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* temp = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = temp;

            temp = curr;
            curr = next;
        }

        // Compare both halves
        ListNode* structnode = head;

        while (temp != NULL) {

            if (structnode->val != temp->val) {
                return false;
            }

            structnode = structnode->next;
            temp = temp->next;
        }

        return true;
    }
};