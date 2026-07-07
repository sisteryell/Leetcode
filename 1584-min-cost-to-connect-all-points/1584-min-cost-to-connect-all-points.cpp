class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size(),cost=0;
        vector<int>vis(v,0);
        vector<int>minDist(v,1e9);
        minDist[0]=0;
        for(int i=0;i<v;i++){
            int u=-1;
            for(int j=0;j<v;j++){
                if(!vis[j] and (u==-1 or minDist[j]<minDist[u])){
                    u=j;
                }
            }
            vis[u]=1;
            cost+=minDist[u];
            for(int j=0;j<v;j++){
                int distance=abs(points[j][0]-points[u][0])+abs(points[j][1]-points[u][1]);
                if(!vis[j] and distance<minDist[j]){
                    minDist[j]=distance;
                }
            }
        }
        return cost;
    }
};