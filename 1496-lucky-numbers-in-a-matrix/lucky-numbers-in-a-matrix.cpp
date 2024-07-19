class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        
        for (int i = 0; i < matrix.size(); ++i) {
            int minVal = matrix[i][0];
            int minIndex = 0;
            
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minIndex = j;
                }
            }
            
            // Check if the minimum value is the maximum in its column
            bool isLucky = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (matrix[k][minIndex] > minVal) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) {
                luckyNumbers.push_back(minVal);
            }
        }
        
        return luckyNumbers;
    }
};
