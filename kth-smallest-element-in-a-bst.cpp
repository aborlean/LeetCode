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
    vector<int> values;
    void inorder(TreeNode* node) {
        if(node->left)
            inorder(node->left);

        values.push_back(node->val);

        if(node->right)
            inorder(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return values[k - 1];
    }
};