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
    int get_h(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_h = get_h(root->left);
        int right_h = get_h(root->right);
        return max(left_h, right_h) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left_h = get_h(root->left);
        int right_h = get_h(root->right);
        return abs(left_h-right_h) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
