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
    // Inorder traversal
    void dfs(TreeNode* root, int& count, int& result) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, count, result);
        --count;
        // Bingo
        if (count == 0) {
            result = root->val;
            return;
        }
        dfs(root->right, count, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int count = k;
        dfs(root, count, result);
        return result;
    }
};
