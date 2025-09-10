class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        function<bool(int,int)> dfs=[&](int i, int j){
            if(i<0 or i>=m or j<0 or j>=n)return false;
            if(grid[i][j]==1)return true;
            grid[i][j]=1;
            bool left=dfs(i,j-1);
            bool right=dfs(i,j+1);
            bool up=dfs(i-1,j);
            bool down=dfs(i+1,j);
            return left and right and up and down;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 and dfs(i,j))ans++;
            }
        }
        return ans;
    }
};