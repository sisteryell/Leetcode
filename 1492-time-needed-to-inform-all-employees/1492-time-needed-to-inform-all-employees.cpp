class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<manager.size();i++){
            int u=manager[i];
            if(u!=-1){
                adj[u].push_back(i);
            }
        }
        int ans=-1;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            auto [emp,time]=q.front();
            q.pop();
            ans=max(ans,time);
            for(int v:adj[emp]){
                q.push({v,time+informTime[emp]});
            }
        }
        return ans;
    }
};