/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1st pass: fill hash
        // hash: <old node, new copied node>
        unordered_map<Node*, Node*> old2new;
        old2new[nullptr] = nullptr;
        Node* curr = head;
        while (curr) {
            old2new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        // 2nd pass: fill copied node
        curr = head;
        while (curr) {
            Node* new_node = old2new[curr];
            new_node->next = old2new[curr->next];
            new_node->random = old2new[curr->random];
            curr = curr->next;
        }
        return old2new[head];
    }
};
