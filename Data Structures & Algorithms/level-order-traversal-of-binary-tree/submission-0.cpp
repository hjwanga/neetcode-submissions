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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        // BFS
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            // 每個level 塞一個vector
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
                result.push_back(move(level_result));
            }
        }

        return result;
    }
};

//   1  -> [[1]]

//   1
// 2     -> [[1],[2]]