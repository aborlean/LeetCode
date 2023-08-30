class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> rows;
        unordered_map<int, bool> columns;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    columns[j] = true;
                }

        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(rows[i] || columns[j])
                    matrix[i][j] = 0;
    }
};