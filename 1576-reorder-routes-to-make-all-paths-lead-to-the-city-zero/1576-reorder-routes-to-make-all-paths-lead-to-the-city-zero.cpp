class Solution {
    int f(int n,vector<vector<int>> &c,vector<bool> &v,vector<vector<int>> &vec,int cur){
        int ans=0;
        for(auto &x:vec[cur]){
            if(v[x]) continue;
            v[x]=true;
            if(c[x][0]==cur) ans+=f(n,c,v,vec,c[x][1])+1;
            else if(c[x][1]==cur) ans+=f(n,c,v,vec,c[x][0]);
            v[x]=false;
        }
        return ans;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections){
        vector<bool>vis(n);
        vector<vector<int>>idx(n);
        for(int j=0;j<connections.size();j++){
            idx[connections[j][0]].emplace_back(j);
            idx[connections[j][1]].emplace_back(j);
        }
        return f( n,connections,vis,idx,0);
    }
};