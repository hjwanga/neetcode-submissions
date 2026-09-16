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
    // 多帶hieght而已
    bool dfs(TreeNode* root, int& h) {
        if (root == nullptr) {
            return true;
        }
        int left_h = 0;
        int right_h = 0;
        bool left_balanced = dfs(root->left, left_h);
        bool right_balanced = dfs(root->right, right_h);
        h = max(left_h, right_h) + 1;
        return left_balanced && right_balanced && abs(left_h - right_h) <= 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return dfs(root, h);
    }
};

// 1. empty -> balanced
// 2. left subtree and right subtree are both balanced
// 3. abs (hieght of left subtree - height of right subtree) <= 1