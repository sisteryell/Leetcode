class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int  j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                bool flag = false;
                for(int col = 0; col < n; col++) {
                    if(col != j && grid[i][col] == 1) {
                        flag = true;
                    }
                }
                if(!flag) {
                    for(int row = 0; row < m; row++) {
                        if(row != i && grid[row][j] == 1) {
                            flag = true;
                        }
                    }
                }
                if(flag) {
                    ans++;
                }
            }
        }
        return ans;
    }
};