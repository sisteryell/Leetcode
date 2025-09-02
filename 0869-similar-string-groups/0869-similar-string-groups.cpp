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
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU dsu(n);
        auto check=[](string& a, string& b)->bool{
            int diff=0;
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i])diff++;
                if(diff>2)return false;
            }
            return true;
        };
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j])){
                    dsu.union_sets(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dsu.find_set(i)==i)ans++;
        }
        return ans;
    }
};