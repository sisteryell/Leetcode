class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto x:times) {
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        while(!pq.empty()) {
            auto [dist,node]=pq.top();
            pq.pop();
            for(auto [v,d]:adj[node]) {
                if(distance[v]>dist+d) {
                    distance[v]=dist+d;
                    pq.push({distance[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(distance[i]==INT_MAX) return -1;
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};