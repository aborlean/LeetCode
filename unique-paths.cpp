class Solution {
public:
    int v[101][101];

    int uniquePaths(int m, int n) {
        v[1][1] = 1;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(i == 1 || j == 1)
                    v[i][j] = 1;
                else
                    v[i][j] += v[i - 1][j] + v[i][j - 1];

        return v[m][n];
    }
};