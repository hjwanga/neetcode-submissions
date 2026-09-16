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
    // preorder: [pre_l, pre_r]
    // inorder: [in_l, in_r]
    TreeNode* dfs(const vector<int>& preorder, const vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r || in_l > in_r)  {
            return nullptr;
        }
        // 1. get root from preorder
        int root_val = preorder[pre_l];
        // 2. split left and right from inorder
        int index_root = -1;
        for (int i = in_l; i <= in_r; ++i) {
            if (inorder[i] == root_val) {
                index_root = i;
                break;
            }
        }
        // 3. get left/right subtree size
        int left_len = index_root - in_l;
        int right_len = in_r-in_l+1-left_len;
        // 4. calculate ranges
        int left_pre_l = pre_l+1;
        int left_pre_r = pre_l+left_len;
        int left_in_l = in_l;
        int left_in_r = in_l+left_len-1;

        int right_pre_l = left_pre_r+1;
        int right_pre_r = pre_r;
        int right_in_l = index_root+1;
        int right_in_r = in_r;

        TreeNode* root = new TreeNode(root_val);
        TreeNode* left = dfs(preorder, inorder, left_pre_l, left_pre_r, left_in_l, left_in_r);
        TreeNode* right = dfs(preorder, inorder, right_pre_l, right_pre_r, right_in_l, right_in_r);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        return dfs(preorder, inorder, 0, m-1, 0, m-1);
    }
};

// pre: [中] |左右
// in: [左] |中右

//     1
//   2   3
// 4    5  6

// pre: 1 2 4 3 5 6
// in : 4 2 1 5 3 6

// pre: [1] | 2 4 3 5 6
// in : 4 2  |1 |5 3 6
//      左   |中| 右

// 1.pre 可以知道root
// 2.in 根據root, 可以區分 左subtree | 右subtree
// 3.根據左subtree個數 可以知道左subtree nodes preorder範圍到哪裡. 同理剩餘的就是右subtree的preorder
// 4.Recursive call with new ranges