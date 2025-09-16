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
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(string& eq:equations){
            if(eq[1]=='='){
                dsu.union_sets(eq[0]-'a',eq[3]-'a');
            }
        }
        for(string& eq:equations){
            if(eq[1]=='!'){
                int a=dsu.find_set(eq[0]-'a');
                int b=dsu.find_set(eq[3]-'a');
                if(a==b)return false;
            }
        }
        return true;
    }
};