class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solve(board))
                                return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == num)
                return false;
        }
        
        // Check column
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num)
                return false;
        }
        
        // Check 3x3 sub-box
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == num)
                    return false;
            }
        }
        
        return true;
    }
};