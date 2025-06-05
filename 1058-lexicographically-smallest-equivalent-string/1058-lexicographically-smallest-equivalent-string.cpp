// class Solution {
//     char dfs(char ch,vector<int>&vis,unordered_map<char,vector<char>>&adj){
//         vis[ch-'a'] = 1;
//         char chr = ch;
//         for(char x : adj[ch]){
//             if(!vis[x - 'a']){
//                 chr = min(chr, dfs(x,vis,adj));
//             }
//         }
//         return chr;
//     }
// public:
//     string smallestEquivalentString(string s1, string s2, string baseStr) {
//         int n = s1.length();
//         unordered_map<char,vector<char>>adj;
//         for(int i=0;i<n;i++){
//             adj[s1[i]].push_back(s2[i]);
//             adj[s2[i]].push_back(s1[i]);
//         }
//         string ans;
//         for(char ch : baseStr){
//             vector<int>vis(26,0);
//             char chr = dfs(ch,vis,adj);
//             ans.push_back(chr);
//         }
//         return ans;
//     }
// };


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
            if(a>b)
                swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])
                rank[a]++;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        DSU dsu(26);
        for(int i=0;i<n;i++){
            char c1 = s1[i], c2 = s2[i];
            dsu.union_sets(c1-'a',c2-'a');
        }
        string ans;
        for(char ch : baseStr){
            ans.push_back(dsu.find_set(ch-'a')+'a');
        }
        return ans;
    }
};