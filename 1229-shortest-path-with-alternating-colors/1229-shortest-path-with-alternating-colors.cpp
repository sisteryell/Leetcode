class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>adj(2*n);
        for(auto& edge:redEdges){
            adj[edge[0]].push_back(n+edge[1]);
        }
        for(auto& edge:blueEdges){
            adj[n+edge[0]].push_back(edge[1]);
        }
        queue<pair<int,int>>q;
        vector<bool>vis(2*n,false);
        q.push({0,0});
        q.push({n,0});
        vis[0]=true;
        vis[n]=true;
        vector<int>ans(n,-1);
        while(!q.empty()){
            auto [curr,dist]=q.front();
            q.pop();
            int u=curr%n;
            if(ans[u]==-1){
                ans[u]=dist;
            }
            for(int v:adj[curr]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push({v,dist+1});
                }
            }
        }
        return ans;
    }
};