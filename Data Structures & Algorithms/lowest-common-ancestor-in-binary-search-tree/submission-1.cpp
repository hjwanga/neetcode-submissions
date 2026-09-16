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
    bool has_p_or_q(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result) {
        if (root == nullptr) {
            return false;
        }
        if (result) {
            return true;
        }
        bool left = has_p_or_q(root->left, p, q, result);
        bool right = has_p_or_q(root->right, p, q, result);
        bool is_myself = root == p || root == q;
        if (!result && (left && right) || (is_myself && (left || right))) {
            result = root;
            return true;
        }
        return left || right || is_myself;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        has_p_or_q(root, p, q, result);
        return result;
    }
};

