class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        function<void(int,int,vector<vector<bool>>&)> dfs=[&](int row, int col, vector<vector<bool>>&vis){
            vis[row][col]=true;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and heights[nr][nc]>=heights[row][col]){
                    dfs(nr,nc,vis);
                }
            }
        };
        for(int i=0;i<m;i++){
            dfs(i,0,pacific);
            dfs(i,n-1,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,pacific);
            dfs(m-1,i,atlantic);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};