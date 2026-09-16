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
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* prev_start = &dummy;
        ListNode* start = curr;
        int count = 0;
        while (curr) {
            // do reverse K group
            if (count > 0 && ((count%k) == 0)) {
                prev->next = nullptr;
                ListNode* reversed_node = reverse(start);
                prev_start->next = reversed_node;
                start->next = curr;
                prev = start;
                prev_start = start;
            }
            // new start
            if ((count%k) == 0) {
                start = curr;
            }
            ++count;
            curr = curr->next;
            prev = prev->next;
        }
        // final round
        // do reverse K group
        if (count > 0 && ((count%k) == 0)) {
            prev->next = nullptr;
            ListNode* reversed_node = reverse(start);
            prev_start->next = reversed_node;
            start->next = curr;
            prev = start;
            prev_start = start;
        }
        return dummy.next;
    }
};

// ListNode* reverse(ListNode* node) {}

//       |                 |
//    dummy      1 -> 2 -> 3  4->5->6
//   start       ^
//   prev                  ^
//   curr                     ^

// reverse
//       |                 
//     dummy ->  3 -> 2 -> 1 -> 4->5->6
//  prev_start             ^
//   start                      ^
//   prev                       ^
//   curr                          ^

