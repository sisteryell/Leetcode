class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,0),ans;
        vector<vector<int>>result;
        function<void(int,int)>dfs=[&](int start, int stop){
            vis[start]=1;
            ans.push_back(start);
            if(start==stop){
                result.push_back(ans);
                ans.pop_back();
                vis[start]=0;
                return;
            }
            for(int u:graph[start]){
                if(vis[u]==0){
                    dfs(u,stop);
                }
            }
            ans.pop_back();
            vis[start]=0;
        };
        dfs(0,v-1);
        return result;
    }
};