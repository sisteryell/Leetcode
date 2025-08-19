class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<tuple<int,int,int>>q;
        q.push({entrance[0],entrance[1],0});
        vis[entrance[0]][entrance[1]]=2;
        while(!q.empty()){
            auto[row,col,step]=q.front();
            q.pop();
            if((row==m-1 or row==0 or col==n-1 or col==0) and vis[row][col]!=2)return step;
            int dr[4]={0,0,-1,1};
            int dc[4]={-1,1,0,0};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and maze[nr][nc]=='.' and !vis[nr][nc]){
                    q.push({nr,nc,step+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};