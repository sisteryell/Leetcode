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
int N;
    int id(int i, int j){
        return N*i+j;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DSU dsu(m*n);
        N=n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i){
                    if((grid[i][j]==2 or grid[i][j]==5 or grid[i][j]==6) and (grid[i-1][j]==2 or grid[i-1][j]==3 or grid[i-1][j]==4)){
                        dsu.union_sets(id(i,j),id(i-1,j));
                    }
                }
                if(j){
                    if((grid[i][j]==1 or grid[i][j]==3 or grid[i][j]==5) and (grid[i][j-1]==1 or grid[i][j-1]==4 or grid[i][j-1]==6)){
                        dsu.union_sets(id(i,j),id(i,j-1));
                    }
                }
            }
        }
        return dsu.find_set(id(0,0))==dsu.find_set(id(m-1,n-1));
    }
};