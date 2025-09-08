class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        auto bfs = [&]()->int{
            int area=1;
            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int row=r+dr[i];
                    int col=c+dc[i];
                    if(row>=0 and row<m and col>=0 and col<n and grid[row][col]==1 and !vis[row][col]){
                        vis[row][col]=1;
                        q.push({row,col});
                        area++;
                    }
                }
            }
            return area;
        };
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    vis[i][j]=1;
                    q.push({i,j});
                    area=max(area,bfs());
                }
            }
        }
        return area;
    }
};