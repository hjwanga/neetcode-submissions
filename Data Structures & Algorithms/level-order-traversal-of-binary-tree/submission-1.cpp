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
    void bfs(TreeNode* root, int level, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        if (result.size() == level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        bfs(root->left, level+1, result);
        bfs(root->right, level+1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, 0, result);
        return result;
    }
};
