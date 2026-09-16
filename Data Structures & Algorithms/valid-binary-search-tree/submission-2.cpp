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
    int get_rightmost(TreeNode* root) {
        int result = INT_MIN;
        TreeNode* curr = root;
        while (curr) {
            result = max(result, curr->val);
            curr = curr->right;
        }
        return result;
    }
    int get_leftmost(TreeNode* root) {
        int result = INT_MAX;
        TreeNode* curr = root;
        while (curr) {
            result = min(result, curr->val);
            curr = curr->left;
        }
        return result;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!root->left && !root->right) {
            return true;
        }
        if (!root->left || !root->right) {
            return root->left ? (get_rightmost(root->left) < root->val) && isValidBST(root->left) : (get_leftmost(root->right) > root->val) && isValidBST(root->right);
        }
        return (get_rightmost(root->left) < root->val && root->val < get_leftmost(root->right)) && isValidBST(root->left) && isValidBST(root->right);
    }
};

// (left_rightmost < root->val) 
// (root->val < right_leftmost)


//    2
///     3

//    2
//  1


//    2
//  1   3

//      3
//    2     5
//        1   6 
//      -1 3