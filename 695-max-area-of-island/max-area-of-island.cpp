class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j){
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0){
            return 0;
        }

        g[i][j] = 0;
        int area = 1;
        area += dfs(g, i - 1, j);
        area += dfs(g, i + 1, j);
        area += dfs(g, i, j - 1);
        area += dfs(g, i, j + 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};