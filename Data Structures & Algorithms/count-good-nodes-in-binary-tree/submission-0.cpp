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
    void dfs(TreeNode* root, int max_val_in_path, int& result) {
        if (root == nullptr) {
            return;
        }
        if (max_val_in_path <= root->val) {
            ++result;
        }
        max_val_in_path = max(max_val_in_path, root->val);
        dfs(root->left, max_val_in_path, result);
        dfs(root->right, max_val_in_path, result);
    }
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, INT_MIN, result);
        return result;
    }
};

//   3
// 3