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
    void create_and_add_to_a_node(ListNode* &curr, int num, int& carry) {
        int final_val = num+carry;
        if (final_val >= 10) {
            final_val -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        curr->next = new ListNode(final_val);
        curr = curr->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;
            create_and_add_to_a_node(curr, val1+val2, carry);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val1 = l1->val;
            create_and_add_to_a_node(curr, val1, carry);
            l1 = l1->next;
        }
        while (l2) {
            int val2 = l2->val;
            create_and_add_to_a_node(curr, val2, carry);
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
