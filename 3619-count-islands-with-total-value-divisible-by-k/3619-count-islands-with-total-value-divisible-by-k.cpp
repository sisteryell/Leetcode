class Solution {
    int rows, cols;
    long long dfs(int r, int c, vector<vector<int>>& grid,
    vector<vector<bool>>& vis) {
        if(r<0 || r>=rows || c<0 || c>=cols){
            return 0;
        }
        if(grid[r][c] ==0 || vis[r][c]) {
            return 0;
        }
        vis[r][c] = true;
        long long sum = grid[r][c];
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        for(int d=0; d<4; d++) {
            sum += dfs(r+dr[d], c+dc[d], grid, vis);
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> vis(
            rows, vector<bool> (cols, false)
        );
        int ans=0;
        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(grid[r][c] > 0 && !vis[r][c]) {
                    long long islandSum = dfs(r, c, grid, vis);
                    if(islandSum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};