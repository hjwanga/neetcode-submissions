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
    ListNode* reverse_node(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = dummy.next;
        ListNode* l = nullptr;
        ListNode* r = nullptr;
        ListNode* prev_l = nullptr;
        ListNode* after_r = nullptr;
        int index = 1;
        // 1. get 4 nodes: prev_l-l--------r-after_r
        while (curr) {
            ListNode* next = curr->next;

            if (index == left) {
                prev_l = prev;
                l = curr;
            }
            if (index == right) {
                r = curr;
                after_r = next;
            }
            ++index;
            prev = curr;
            curr = next;
        }
        // 2. reverse list [l,r]
        r->next = nullptr;
        prev_l->next = reverse_node(l);
        l->next = after_r;
        return dummy.next;
    }
};


//   prev_l->l ------> r -> after_r

//   1.(r->next = nullptr;)
//    prev_l->l ------> r. after_r
//                      v
//                     nullptr

//   2. (reverse_node)
//  prev_l -> l <------ r. after_r
//            v
//           nullptr

//   3. prev_l->next = reverse_node
//   prev_l -> r ---------> l. after_r
//                          v
//                         nullptr

//   4. l->next = after_r
//   prev_l -> r ---------> l -> after_r



