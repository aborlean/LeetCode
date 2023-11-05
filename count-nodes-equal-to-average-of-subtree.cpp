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
    int count;

    pair<int, int> calcul(TreeNode* node) {
        if(!node)
            return {0, 0};

        auto l = calcul(node->left);
        auto r = calcul(node->right);

        int s = l.first + r.first + node->val;
        int n = l.second + r.second + 1;

        if(s / n == node->val)
            count++;

        return {s, n};
    }
    int averageOfSubtree(TreeNode* root) {
        calcul(root);
        return count;
    }
};