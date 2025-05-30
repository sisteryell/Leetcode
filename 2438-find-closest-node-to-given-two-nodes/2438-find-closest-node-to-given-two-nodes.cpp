class Solution {
public:
    void dfs(int x, int d, vector<int>&adj,vector<int>&dist){
        while(x!=-1 and dist[x]==-1){
            dist[x]=d++;
            x=adj[x];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans=-1,mn=1e9,n=edges.size();
        vector<int>d1(n,-1),d2(n,-1);
        dfs(node1,0,edges,d1);
        dfs(node2,0,edges,d2);
        for(int i=0;i<n;i++){
            if(d1[i]>=0 and d2[i]>=0){
                int mx=max(d1[i],d2[i]);
                if(mx<mn){
                    mn=mx;
                    ans=i;
                }
            }
        }
        return ans;
    }
};