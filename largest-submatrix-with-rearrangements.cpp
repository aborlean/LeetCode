class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(matrix[i][j] && i > 0)
                    matrix[i][j] += matrix[i - 1][j];

            vector<int> current = matrix[i];
            sort(current.begin(), current.end(), greater());
            for(int x = 0; x < m; x++)
                ans = max(ans, current[x] * (x + 1));
        }

        return ans;
    }
};