class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            auto [axis,t] = q.front(); auto [row,col] = axis; q.pop();
            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                if(newrow>=0 and newrow<m and newcol>=0 and newcol<n and grid[newrow][newcol]==1){
                    q.push({{newrow,newcol},t+1});
                    grid[newrow][newcol] = 2;
                    time = t+1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};