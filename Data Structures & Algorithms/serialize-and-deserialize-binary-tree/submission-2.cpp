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

class Codec {
    void dfs1(TreeNode* root, stringstream& ss) {
        if (root == nullptr) {
            ss << "N ";
            return;
        }
        ss << to_string(root->val) + " ";
        dfs1(root->left, ss);
        dfs1(root->right, ss);
    }
    TreeNode* dfs2(stringstream& ss) {
        string token;
        ss >> token;
        if (token == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = dfs2(ss);
        root->right = dfs2(ss);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       stringstream ss;
       dfs1(root, ss);
       return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dfs2(ss);
    }
};
