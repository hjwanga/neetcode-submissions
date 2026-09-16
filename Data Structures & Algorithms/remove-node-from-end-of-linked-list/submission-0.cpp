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
    int get_len(ListNode* head) {
        int result = 0;
        while (head) {
            head = head->next;
            ++result;
        }
        return result;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1st pass: 計算長度
        int len = get_len(head);
        // 2nd pass: 刪除
        int target_index = len-n; //0-based
        ListNode dummy;
        ListNode* prev = &dummy;
        prev->next = head;
        ListNode* curr = head;
        int index = 0;
        while (curr) {
            ListNode* next = curr->next;
            if (index == target_index) {
                prev->next = next;
                curr->next = nullptr;
                break;
            }
            prev = curr;
            curr = next;
            ++index;
        }
        return dummy.next;
    }
};
// prev curr next
//   A -> B -> C
//   A -> C
//   B->nullptr
