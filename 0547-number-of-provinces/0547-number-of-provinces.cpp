class Solution {
    void dfs(int start, vector<int>&vis, vector<int>adj[]){
        vis[start]=1;
        for(int x:adj[start]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};