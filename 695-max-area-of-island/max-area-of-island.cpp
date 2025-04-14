class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        grid[r][c] = 0;
        int area = 1;

        for (auto& d : dir) {
            int newR = r + d[0];
            int newC = c + d[1];
            if(newR >= 0 && newC >= 0 && newR < rows && newC < cols && grid[newR][newC] == 1) {
                area += dfs(grid, newR, newC);
            }
        }

        // area += dfs(grid, r, c - 1);
        // area += dfs(grid, r, c + 1);
        // area += dfs(grid, r - 1, c);
        // area += dfs(grid, r + 1, c);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};
