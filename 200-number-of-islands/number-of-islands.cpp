class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        // if element is '0', or if the index is out of bounds, 
        // either negative or greater than the bound size
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};