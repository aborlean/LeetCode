class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int distance = 0;

        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                if(!mat[i][j])
                    q.push({i, j});
                else
                    mat[i][j] = INT_MAX;

        while(!q.empty()) {
            int i = q.size();
            distance++;
            while(i--) {
                pair<int, int> p = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int new_x = p.first + dx[k];
                    int new_y = p.second + dy[k];
                    if(new_x >= 0 && new_y >= 0 && new_x < mat.size() && new_y < mat[0].size() && mat[new_x][new_y] == INT_MAX) {
                        mat[new_x][new_y] = distance;
                        q.push({new_x, new_y});
                    }
                }
            }
        }

        return mat;
    }
};