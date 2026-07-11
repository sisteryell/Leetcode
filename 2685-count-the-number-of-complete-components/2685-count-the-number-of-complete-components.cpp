class Solution {
    void dfs(int node, int &countNode, int &countEdge, vector<int> &vis, vector<int> adj[]) {
        vis[node]=1;
        countNode++;
        for(int nbr: adj[node]){
            countEdge++;
            if(!vis[nbr]){
                dfs(nbr,countNode,countEdge,vis,adj);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            int countNode=0, countEdge=0;
            if(!vis[i]){
                dfs(i,countNode,countEdge,vis, adj);
                if(countEdge==countNode*(countNode-1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};