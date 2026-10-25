class Solution {
    int rows, cols;
    bool touch;
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }
        if(grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        for(int d=0; d<4; d++) {
            dfs(r+dr[d], c+dc[d], grid);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int closed = 0;
        for(int r=0; r<rows; r++) {
            if(grid[r][0] == 0) {
                dfs(r, 0, grid);
            }
            if(grid[r][cols-1] == 0) {
                dfs(r, cols-1, grid);
            } 
        }
        for(int c=0; c<cols; c++) {
            if(grid[0][c] == 0) {
                dfs(0, c, grid);
            }
            if(grid[rows-1][c] == 0) {
                dfs(rows-1, c, grid);
            } 
        }
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] == 0) {
                    closed++;
                    dfs(r, c, grid);
                }
            }
        }
        return closed;
    }
};