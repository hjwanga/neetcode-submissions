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
    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int root_val = root->val;
        int l_val = dfs(root->left, result);
        int r_val = dfs(root->right, result);
        result = max(result, root_val + max({0, l_val, r_val, l_val+r_val}));
        return root_val + max({0, l_val, r_val});
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
};


// int dfs(root, result)
// rval: return max path sum from this root

// 1. root
// 2. left - root
// 3. right - root

// result: max(1, 2, 3, left-root-right)