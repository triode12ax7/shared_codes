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
    vector<string> result;

    void print_helper(TreeNode* root) {
            if (root == nullptr) { return; }

            print_helper(root->left);
            result.push_back(to_string(root->val));
            print_helper(root->right);
    }

    void print(TreeNode* root) {
        print_helper(root);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        print(root);
        return result;
    }
};
