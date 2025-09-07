
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<tuple<int,int,int>>qq;
        queue<pair<int,int>>q;
        bool found=false;
        for(int i=0;i<m and !found;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    found=true;
                    break;
                }
            }
        }
        int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=x+dx[i],nc=y+dy[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc]){
                    if(grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }else{
                        qq.push({0,nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        while(!qq.empty()){
            auto [dis,r,c]=qq.front();
            qq.pop();
            if(grid[r][c]==1)return dis;
            for(int i=0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc]){
                    qq.push({dis+1,nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return 0;
    }
};