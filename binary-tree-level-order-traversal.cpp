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

    void search(TreeNode* node, int level, vector<vector<int>>& ans) {
        if(!node)
            return;
        if(level >= ans.size())
            ans.push_back({});

        ans[level].push_back(node->val);
        search(node->left, level + 1, ans);
        search(node->right, level + 1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root)
            return ans;

        search(root, 0, ans);

        return ans;
    }
};