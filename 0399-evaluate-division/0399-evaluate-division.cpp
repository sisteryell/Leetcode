class disjointset{
public:
    vector<int>parent,size;
    disjointset(int n){
        parent.resize(n,1);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int up=findpar(u);
        int vp=findpar(v);
        if(up==vp){
            return;
        }
        if(size[vp]>size[up]){
            size[vp]+=size[up];
            parent[up]=vp;
        }
        else{
            size[up]+=size[vp];
            parent[vp]=up;
        }
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        vector<vector<pair<int,double>>>adj(26);
        unordered_map<string,int>mp;
        int size=0;
        for(int i=0;i<n;i++){
            string s1=equations[i][0];
            string s2=equations[i][1];
            if(mp.find(s1)==mp.end()){
                mp[s1]=size;
                size++;
            }
            if(mp.find(s2)==mp.end()){
                mp[s2]=size;
                size++;
            }
            int u=mp[s1];
            int v=mp[s2];
            double wt=values[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,1/wt});
        }
        disjointset ds(size+1);
        for(int i=0;i<n;i++){
            int u=mp[equations[i][0]];
            int v=mp[equations[i][1]];
            ds.unionbysize(u,v);
        }
        int m=queries.size();
        vector<double>ans;
        for(int i=0;i<m;i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(mp.find(start)==mp.end() || mp.find(end)==mp.end()){
                ans.push_back(-1.0);
                continue;
            }
            if(start==end){
                ans.push_back(1.0);
                continue;
            }
            int u=mp[start];
            int v=mp[end];
            if(ds.findpar(u)!=ds.findpar(v)){
                ans.push_back(-1.0);
                continue;
            }
            priority_queue<pair<int,double>,vector<pair<int,double>>,greater<pair<int,double>>>pq;
            vector<int>visited(size+1,0);
            visited[u]=1;
            pq.push({u,1.0});
            double res=1;
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                int node=it.first;
                double val=it.second;
                if(node==v){
                    res=val;
                    break;
                }
                for(auto temp:adj[node]){
                    int adjNode=temp.first;
                    double adjVal=temp.second;
                    double new_val=val*adjVal;
                    if(visited[adjNode]==0){
                        visited[adjNode]=1;
                        pq.push({adjNode,new_val});
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};