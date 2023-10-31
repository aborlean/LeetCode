class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1)
                v[leftChild[i]]++;
            if (rightChild[i] != -1)
                v[rightChild[i]]++;
        }

        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) {
                if (root == -1)
                    root = i;
                else
                    return false;
            }
        }
        if (root == -1)
            return false;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (visited[node])
                return false;
            visited[node] = true;
            if (leftChild[node] != -1)
                q.push(leftChild[node]);
            if (rightChild[node] != -1)
                q.push(rightChild[node]);
        }

        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};