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

    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        while (h1 && h2) {
            curr->next = h1;
            h1 = h1->next;
            curr = curr->next;

            curr->next = h2;
            h2 = h2->next;
            curr = curr->next;
        }
        while (h1) {
            curr->next = h1;
            h1 = h1->next;
            curr = curr->next;
        }
        return dummy.next;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rhs_head = reverseList(slow->next);
        slow->next = nullptr;
        head = mergeList(head, rhs_head);
    }
};

// len = 4
//  [2,4,6,8] -> [2,8,4,6]
// s     ^
// f         ^
// 左半:2->4->6
// 右半:8

// len = 5
//  [2,4,6,8,10] -> [2,10,4,8,6]
// s     ^ 
// f          ^ 
// 左半:2->4->6
// 右半:10->8

//1.
// 左半:正
// 右半:reverse
//2. merge