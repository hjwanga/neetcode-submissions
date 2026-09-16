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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;
            int final_val = val1+val2+carry;
            if (final_val >= 10) {
                final_val -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->next = new ListNode(final_val);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val1 = l1->val;
            int final_val = val1+carry;
            if (final_val >= 10) {
                final_val -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->next = new ListNode(final_val);
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2) {
            int val2 = l2->val;
            int final_val = val2+carry;
            if (final_val >= 10) {
                final_val -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->next = new ListNode(final_val);
            curr = curr->next;
            l2 = l2->next;
        }
        // pitfall
        if (carry) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return dummy.next;
    }
};
