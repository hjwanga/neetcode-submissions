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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* slow = head;
        ListNode* fast = head;
        // move fast n times
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }
        // slow is in the Nth element
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return dummy.next;
    }
};

//   0 1 2 3 4
//   6 7 8 9 10, n=2 -> 6 7 8 10
//         ^
// s       ^
// f           ^
