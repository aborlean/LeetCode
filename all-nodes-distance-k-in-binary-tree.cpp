#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    vector<int> v;
    unordered_map<TreeNode*, TreeNode*> p;
    set<int> seen;

public:

    void find(TreeNode* node, int k) {
        if(!node)
            return;

        seen.insert(node->val);

        if(k == 0) {
            v.push_back(node->val);
            return;
        }


        if(seen.find(node->left->val) == seen.end())
            find(node->left, k - 1);

        if(seen.find(node->right->val) == seen.end())
            find(node->right, k - 1);

        if(seen.find(p[node]->val) == seen.end())
            find(p[node], k - 1);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                p[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                p[node->right] = node;
                q.push(node->right);
            }
        }

        find(target, k);

        return v;
    }
};