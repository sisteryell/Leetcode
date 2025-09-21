class Solution {
    vector<int>topo(auto& adj, vector<int>& deg, int sz){
        queue<int>q;
        for(int i=0;i<sz;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int y:adj[x]){
                deg[y]--;
                if(deg[y]==0)q.push(y);
            }
        }
        for(int i=0;i<sz;i++){
            if(deg[i]>0)return {};
        }
        return ans;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1)group[i]=m++;
        }
        vector<vector<int>>adj(n);
        vector<int>groups(m,0),items(n,0);
        vector<unordered_set<int>>groupset(m);
        for(int i=0;i<n;i++){
            int x=group[i];
            for(int item:beforeItems[i]){
                int y=group[item];
                if(x!=y and groupset[y].count(x)==0){
                    groupset[y].insert(x);
                    groups[x]++;
                }
                adj[item].push_back(i);
                items[i]++;
            }
        }
        vector<int> sg=topo(groupset,groups,m);
        vector<int> si=topo(adj,items,n);
        if(sg.empty() or si.empty())return {};
        vector<vector<int>> ig(m);
        for(int x:si){
            ig[group[x]].push_back(x);
        }
        vector<int>ans;
        for(int x:sg){
            for(int y:ig[x]){
                ans.push_back(y);
            }
        }
        return ans;
    }
};