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
    void inorder(TreeNode* node, vector<int>& v) {
        if(!node)
            return;
        v.push_back(node->val);
        inorder(node->left, v);
        inorder(node->right, v);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> inord;
        inorder(root, inord);
        unordered_map<int, int> m;
        int ma = 0;

        for(int x : inord) {
            m[x]++;
            ma = max(ma, m[x]);
        }

        vector<int> ans;
        for(auto x: m) {
            if(x.second == ma)
                ans.push_back(x.first);
        }

        return ans;
    }
};