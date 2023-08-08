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
    void search(TreeNode* node, int& depth, int current)
    {
        if(!node)
            return;
        if(current > depth)
            depth = current;

        search(node->left, depth, current + 1);
        search(node->right, depth, current + 1);
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;

        search(root, depth, 1);

        return depth;
    }
};