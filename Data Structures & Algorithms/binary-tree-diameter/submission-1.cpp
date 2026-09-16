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
    // return longest length from root
    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int left_len = dfs(root->left, result);
        int right_len = dfs(root->right, result);
        result = max(result, left_len + right_len);
        return max(left_len, right_len) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

