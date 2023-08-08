class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size() - 1;

        while(up <= down) {
            int row = (up + down) / 2;
            if(target >= matrix[row][0] && target <= matrix[row][matrix[row].size() - 1]) {
                int left = 0, right = matrix[row].size() - 1;
                while(left <= right) {
                    int column = (left + right) / 2;
                    if(matrix[row][column] == target)
                        return true;
                    if(matrix[row][column] < target)
                        left = column + 1;
                    else
                        right = column - 1;
                }
                return false;
            }
            else if(target < matrix[row][0])
                down = row - 1;
            else
                up = row + 1;
        }
        return false;
    }
};