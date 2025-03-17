class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; 

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ret;

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while (top <= bottom && left <= right) {
            // Move right
            for (int j = left; j <= right; j++)
                ret.push_back(matrix[top][j]);
            top++;

            // Move down
            for (int i = top; i <= bottom; i++)
                ret.push_back(matrix[i][right]);
            right--;

            // Move left (if still valid)
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ret.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Move up (if still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ret.push_back(matrix[i][left]);
                left++;
            }
        }

        return ret;
    }
};