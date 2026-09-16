/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void bfs(TreeNode* root, vector<int>& result) {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int right_most_val = INT_MAX;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node == nullptr) {
                    continue;
                }
                right_most_val = node->val;
                que.push(node->left);
                que.push(node->right);
            }
            if (right_most_val != INT_MAX) {
                result.push_back(right_most_val);
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS
        vector<int> result;
        bfs(root, result);
        return result;
    }
};
