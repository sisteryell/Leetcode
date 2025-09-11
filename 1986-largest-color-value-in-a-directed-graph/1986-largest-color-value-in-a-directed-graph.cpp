class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<char>color(colors.begin(),colors.end());
        int n=colors.size();
        vector<int>adj[n+1];
        vector<int>indegree(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int u=0;u<n;u++){
            if(indegree[u]==0){
                q.push(u);
            }
        }
        vector<vector<int>>dp(n,vector<int>(26));
        int ans=0;
        int visited=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            visited++;
            int clr=color[u]-'a';
            dp[u][clr]++;
            ans=max(ans,dp[u][clr]);
            for(int v:adj[u]){
                for(int c=0;c<26;c++){
                    dp[v][c]=max(dp[v][c],dp[u][c]);
                }
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(visited==n)return ans;
        return -1;
    }
};