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
    void bfs(TreeNode* root, vector<vector<int>>& result) {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> level_result;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node == nullptr) {
                    continue;
                }
                level_result.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            if (!level_result.empty()) {
                result.push_back(std::move(level_result));
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS
        vector<vector<int>> bfs_result;
        bfs(root, bfs_result);
        
        // Fill result
        vector<int> result;
        for (const vector<int>& one_level_result : bfs_result) {
            if (one_level_result.empty()) {
                continue;
            }
            result.push_back(one_level_result.back());
        }
        return result;
    }
};
