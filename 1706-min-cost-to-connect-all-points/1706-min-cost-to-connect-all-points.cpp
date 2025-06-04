
//-------------------------------PRIM's ALGORITHM---------------------------------------
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int cost = 0, v = points.size();
//         vector<int>vis(v,0);
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         pq.push({0,0});
//         while(!pq.empty()){
//             auto [wt, node] = pq.top();
//             pq.pop();
//             if(vis[node])continue;
//             vis[node] = 1;
//             cost += wt;
//             for(int i=0;i<v;i++){
//                 int dist = abs(points[i][0]-points[node][0])+
//                            abs(points[i][1]-points[node][1]);
//                 if(!vis[i]){
//                     pq.push({dist,i});
//                 }
//             }
//         }
//         return cost;
//     }
// };







//----------------------------------KRUSKAL's ALGORITHM----------------------------------
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>edges;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        DSU dsu(n);
        int cost = 0;
        for(auto x : edges){
            auto [dist, inner] = x;
            auto [u, v] = inner;
            if(dsu.find_set(u)!=dsu.find_set(v)){
                cost += dist;
                dsu.union_sets(u,v);
            }
        }
        return cost;
    }
};