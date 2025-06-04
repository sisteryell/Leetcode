class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0, v = points.size();
        vector<int>vis(v,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            if(vis[node])continue;
            vis[node] = 1;
            cost += wt;
            for(int i=0;i<v;i++){
                int dist = abs(points[i][0]-points[node][0])+
                           abs(points[i][1]-points[node][1]);
                if(!vis[i]){
                    pq.push({dist,i});
                }
            }
        }
        return cost;
    }
};