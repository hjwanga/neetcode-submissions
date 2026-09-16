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
    bool is_same(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2) {
            return false;
        }
        bool is_same_left = is_same(root1->left, root2->left);
        bool is_same_right = is_same(root1->right, root2->right);
        return is_same_left && is_same_right && root1->val == root2->val;
    }
    void dfs(TreeNode* root, TreeNode* sub_root, bool& result) {
        if (root == nullptr) {
            return;
        }
        bool same = is_same(root, sub_root);
        if (same) {
            result = true;
            return;
        }
        dfs(root->left, sub_root, result);
        dfs(root->right, sub_root, result);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool result = false;
        dfs(root, subRoot, result);
        return result;
    }
};
