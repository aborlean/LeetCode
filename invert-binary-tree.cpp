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
    TreeNode* flip(TreeNode* node) {
        if(!node)
            return NULL;

        flip(node->left);
        flip(node->right);

        TreeNode* aux = node->left;
        node->left = node->right;
        node->right = aux;

        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return flip(root);
    }
};