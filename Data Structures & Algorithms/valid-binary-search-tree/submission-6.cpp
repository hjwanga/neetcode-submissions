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
    // inorder BST: sorted sequence
    bool dfs(TreeNode* root, TreeNode* &prev_node) {
        if (root == nullptr) {
            return true;
        }
        if (!dfs(root->left, prev_node)) {
            return false;
        }
        if (prev_node && prev_node->val >= root->val) {
            return false;
        }
        prev_node = root;
        return dfs(root->right, prev_node);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev_node = nullptr;
        return dfs(root, prev_node);
    }
};
