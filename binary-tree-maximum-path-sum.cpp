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
    int search(TreeNode* node, int& ma) {
        if(!node)
            return 0;

        int first = max(0, search(node->left, ma));
        int second = max(0, search(node->right, ma));

        ma = max(ma, first + second + node->val);

        return max(first, second) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int ma = INT_MIN;

        search(root, ma);

        return ma;
    }
};