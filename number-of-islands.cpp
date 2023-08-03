class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool map[301][301];

    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void fill(int x, int y) {
        map[x][y] = false;
        for(int k = 0; k < 4; k++) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            if(inside(new_x, new_y) && map[new_x][new_y])
                fill(new_x, new_y);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '1')
                    map[i][j] = true;

        int count = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(map[i][j]) {
                    count++;
                    fill(i, j);
                }

        return count;
    }
};