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
        if (!root->left && !root->right) {
            result = max(result, root_val);
            return root_val;
        }
        if (!root->left || !root->right) {
            if (root->left) {
                int l_val = dfs(root->left, result);
                int sol = max(root_val, root_val + l_val);
                result = max(result, sol);
                return sol;
            }
            else {
                int r_val = dfs(root->right, result);
                int sol = max(root_val, root_val + r_val);
                result = max(result, sol);
                return sol;
            }
        }
        int l_val = dfs(root->left, result);
        int r_val = dfs(root->right, result);
        int sol1 = root_val;
        int sol2 = root_val + l_val;
        int sol3 = root_val + r_val;
        int sol4 = root_val + l_val + r_val;
        result = max({result, sol1, sol2, sol3, sol4});
        return max({sol1, sol2, sol3});
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