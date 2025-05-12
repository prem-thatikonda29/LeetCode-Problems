class Solution {
public:
    void dfs(vector<vector<char>> & arr, int i, int j){
        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == '0'){
            return;
        }

        arr[i][j] = '0';
        dfs(arr, i - 1, j);
        dfs(arr, i + 1, j);
        dfs(arr, i, j + 1);
        dfs(arr, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};