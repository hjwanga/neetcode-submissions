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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        bool same_left = isSameTree(p->left, q->left);
        bool same_right = isSameTree(p->right, q->right);
        return same_left && same_right && p->val == q->val;
    }
};

// case1
//    1       1
//  2   3    2  3

// case2
//    1        1
//  2   3    2  

// case2
//            1
//          2  