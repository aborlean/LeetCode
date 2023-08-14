class Solution {
public:
    int v[101][101];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;

        v[0][0] = 1;

        for(int i = 0; i < obstacleGrid.size(); i++)
            for(int j = 0; j < obstacleGrid[i].size(); j++)
                if(!obstacleGrid[i][j]) {
                    if(i - 1 >= 0 && !obstacleGrid[i - 1][j])
                        v[i][j] += v[i - 1][j];
                    if(j - 1 >= 0 && !obstacleGrid[i][j - 1])
                        v[i][j] += v[i][j - 1];
                }

        return v[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};