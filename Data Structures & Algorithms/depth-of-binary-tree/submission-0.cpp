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
    void dfs(TreeNode* root, int depth, int& result) {
        if (root == nullptr) {
            return;
        }

        ++depth;
        if (root->left == nullptr && root->right == nullptr) {
            result = max(result, depth);
            return;
        }
        dfs(root->left, depth, result);
        dfs(root->right, depth, result);
    }
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        return result;
    }
};
// [] -> 0
// 1  -> 1

//    1
//  2   3