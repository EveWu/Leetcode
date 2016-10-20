class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int column = matrix[0].size(), i, j, left_count, right_count, maxRec, area;
        vector<int> left(column,0), right(column,column-1), height(column,0);
        for (i = 0; i < row; i++) {
            left_count = 0;
            right_count = column - 1;
            for (j = column - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    right[j] = column - 1;
                    right_count = j - 1;
                } else {
                    right[j] = min(right[j], right_count);
                }
            }
            for (j = 0; j < column; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                    left[j] = 0;
                    left_count = j + 1;
                } else {
                    height[j]++;
                    left[j] = max(left[j], left_count);
                    area = height[j] * (right[j] - left[j] + 1);
                    maxRec = max(maxRec, area);
                }
                
            }
        }
        return maxRec;
    }
};