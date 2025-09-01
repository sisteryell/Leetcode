class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        int sx=-1,sy=-1,k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=grid[i][j];
                if(ch=='@'){
                    sx=i;
                    sy=j;
                }if(ch>='a' and ch<='z'){
                    k++;
                }
            }
        }
        int target=(1<<k)-1;
        if(target==0)return 0;
        vector<vector<vector<char>>>vis(m,vector<vector<char>>(n,vector<char>(1<<k,0)));
        queue<array<int,3>>q;
        q.push({sx,sy,0});
        vis[sx][sy][0]=1;
        int steps=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();q.pop();
                int row=curr[0],col=curr[1],mask=curr[2];
                for(int dir=0;dir<4;dir++){
                    int nrow=row+dr[dir];
                    int ncol=col+dc[dir];
                    if(nrow<0 or nrow>=m or ncol<0 or ncol>=n)continue;
                    char ch=grid[nrow][ncol];
                    if(ch=='#')continue;
                    int nmask=mask;
                    if(ch>='A' and ch<='Z'){
                        int bit=ch-'A';
                        if((mask & (1<<bit))==0)continue;
                    }else if(ch>='a' and ch<='z'){
                        int bit=ch-'a';
                        nmask=mask | (1<<bit);
                    }
                    if(vis[nrow][ncol][nmask])continue;
                    if(nmask==target)return steps+1;
                    vis[nrow][ncol][nmask]=1;
                    q.push({nrow,ncol,nmask});
                }
            }
            steps++;
        }
        return -1;
    }
};