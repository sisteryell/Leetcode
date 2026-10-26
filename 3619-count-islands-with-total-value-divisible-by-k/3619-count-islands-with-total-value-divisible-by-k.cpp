class Solution {
    int rows, cols;
    long long dfs(int r, int c, vector<vector<int>>& grid) {
        if(r<0 || r>=rows || c<0 || c>=cols){
            return 0;
        }
        if(grid[r][c] ==0) {
            return 0;
        }
        long long sum = grid[r][c];
        grid[r][c] = 0;
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        for(int d=0; d<4; d++) {
            sum += dfs(r+dr[d], c+dc[d], grid);
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        int ans=0;
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] > 0) {
                    long long islandSum = dfs(r, c, grid);
                    if(islandSum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};