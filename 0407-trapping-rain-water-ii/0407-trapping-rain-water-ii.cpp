class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if(m<3 or n<3)return 0;
        vector<vector<int>>vis(m,vector<int>(n));
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>>pq;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 or j==0 or i==m-1 or j==n-1){
                    pq.emplace(heightMap[i][j],i,j);
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()) {
            auto [H,x,y] = pq.top();pq.pop();
            for(auto& d: dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 and nx<m and ny>=0 and ny<n and !vis[nx][ny]) {
                    vis[nx][ny]=1;
                    ans += max(0, H - heightMap[nx][ny]);
                    pq.emplace(max(heightMap[nx][ny],H),nx,ny);
                }
            }
        }
        return ans;
    }
};