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
    ListNode* reverseList(ListNode* head) {
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
};

//        0->1->2->3->4
// prev ^
// curr   ^
// next      ^

// curr->next = prev
//      <-0 1->2->3->4
// prev ^
// curr   ^
// next     ^

// prev = curr
//      <-0 1->2->3->4
// prev   ^
// curr   ^
// next     ^

// curr = next
//      <-0 1->2->3->4
// prev   ^
// curr     ^
// next     ^