vector<int> adj[5555];
int n,aa[5555];
vector<int> v;
int fe[5555],ed[5555],D;
int dfs(int x,int f) {
    int o=v[x];fe[x]=++D;
    for(auto b:adj[x]) if(b!=f) {
        o^=dfs(b,x);
    }
    ed[x]=D;
    aa[x]=o;
    return o;
}
class Solution {
public:
    int minimumScore(vector<int>& s, vector<vector<int>>& e) {
        v=s; n=s.size();D=0;
        for(int i=0;i<n;++i)adj[i].clear();
        for(auto t:e) {
            int p=t[0],q=t[1];
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        int all=dfs(0,-1),ans=2e9;
        for(int x=1;x<n;++x)
            for(int y=1;y<n;++y) if(x!=y) {
                if(ed[x]-fe[x]>ed[y]-fe[y]) continue;
                int s[3];
                if(fe[y]<=fe[x]&&ed[x]<=ed[y]) {
                    s[0]=aa[x];
                    s[1]=aa[y]^aa[x];
                    s[2]=all^aa[y];
                }
                else {
                    s[0]=aa[x];
                    s[1]=aa[y];
                    s[2]=all^s[0]^s[1];
                }
                sort(s,s+3);
                ans=min(ans,s[2]-s[0]);
            }
        return ans;
    }
};