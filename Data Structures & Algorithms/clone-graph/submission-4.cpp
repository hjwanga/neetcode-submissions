/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // <old node, new node>
        unordered_map<Node*, Node*> old2new;
        old2new[node] = new Node(node->val);
        // <old node>
        queue<Node*> que;
        que.push(node);
        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();
            // traverse neighbors
            for (Node* neighbor : curr->neighbors) {
                if (old2new.count(neighbor)) {
                    old2new[curr]->neighbors.push_back(old2new[neighbor]);
                    continue;
                }
                old2new[neighbor] = new Node(neighbor->val);
                old2new[curr]->neighbors.push_back(old2new[neighbor]);
                que.push(neighbor);
            }
        }
        return old2new[node];
    }
};
