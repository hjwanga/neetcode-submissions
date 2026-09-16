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
    using State = pair<int, ListNode*>;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* curr = &dummy;

        // get min element from lists
        auto cmp = [](const State& lhs, const State& rhs){
            if (lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return false;
        };
        priority_queue<State, vector<State>, decltype(cmp)> pq;
        for (auto& head : lists) {
            if (head == nullptr) {
                continue;
            }
            pq.emplace(head->val, head);
        }

        while (!pq.empty()) {
            auto [val, node]= pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            // push next node
            if (node && node->next) {
                pq.emplace(node->next->val, node->next);
            }
        }

        return dummy.next;
    }
};


// [1 3] [2 4]
// l1: [1 3]
// l2: [2 4]

// [4, l2_node1]

// dummy -> l1_node0 -> l2_node0 -> l1_node1 -> l2_node2
//                                                curr

