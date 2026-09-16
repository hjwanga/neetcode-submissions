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
    ListNode* get_kth_node(ListNode* node, int k) {
        ListNode* curr = node;
        while (curr && k > 0) {
            --k;
            curr = curr->next;
        }
        return curr;
    }
    ListNode* reverse(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = nullptr;
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
        ListNode* group_prev = &dummy;
        while (true) {
            ListNode* kth_node = get_kth_node(group_prev, k);
            if (!kth_node) {
                break;
            }
            ListNode* kth_node_next = kth_node->next;
            ListNode* group_curr = group_prev->next;
            kth_node->next = nullptr;
            reverse(group_curr);
            group_prev->next = kth_node;
            group_curr->next = kth_node_next;
            group_prev = group_curr;
        }
        return dummy.next;
    }
};

//        dummy -> 1 -> 2 -> 3 -> 4
// gp_prev  ^
// gp_curr         ^
// kth_node                  ^
// kth_node_next                  ^

//            -------------V
//        dummy  3 -> 2 -> 1   4
// gp_prev  ^
// gp_curr                 ^
// kth_node      ^
// kth_node_next               ^

//            
//        dummy -> 3 -> 2 -> 1 ->  4
// gp_prev  ^
// gp_curr                   ^
// kth_node        ^
// kth_node_next                   ^

