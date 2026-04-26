class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        function<bool(int, int, int, int, char)>dfs=[&](int x, int y, int px, int py, char ch){
            vis[x][y]=true;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 or ny<0 or nx>=m or ny>=n)continue;
                if(grid[nx][ny]!=ch)continue;
                if(!vis[nx][ny]){
                    if(dfs(nx,ny,x,y,ch))return true;
                }else{
                    if(nx!=px or ny!=py)return true;
                }
            }
            return false;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j]))return true;
                }
            }
        }
        return false;
    }
};