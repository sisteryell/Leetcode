class DSU{
    vector<int> parent, rank;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find_set(int v){
        if(v==parent[v])
            return v;
        return parent[v]=find_set(parent[v]);
    }
    void union_sets(int a, int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(rank[a]<rank[b])
                swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])
                rank[a]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>ump;
        int m=accounts.size();
        DSU dsu(m+1);
        for(int i=0;i<m;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(ump.find(accounts[i][j])==ump.end()){
                    ump[accounts[i][j]]=i;
                }else{
                    dsu.union_sets(ump[accounts[i][j]],i);
                }
            }
        }
        for(auto& x:ump){
            ump[x.first]=dsu.find_set(x.second);
        }
        vector<vector<string>>st(accounts.size(),vector<string>(0));
        unordered_set<int>us;
        for(auto& x:ump){
            if(us.find(x.second)!=us.end()){
                st[x.second].push_back(x.first);
            }else{
                st[x.second].push_back(accounts[x.second][0]);
                us.insert(x.second);
                st[x.second].push_back(x.first);
            }
        }
        vector<vector<string>>ans;
        for(auto& x:st){
            if(x.size()!=0){
                sort(x.begin()+1,x.end());
                ans.push_back(x);
            }
        }
        return ans;
    }
};