class Solution {
    char dfs(char ch,vector<int>&vis,unordered_map<char,vector<char>>&adj){
        vis[ch-'a'] = 1;
        char chr = ch;
        for(char x : adj[ch]){
            if(!vis[x - 'a']){
                chr = min(chr, dfs(x,vis,adj));
            }
        }
        return chr;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans;
        for(char ch : baseStr){
            vector<int>vis(26,0);
            char chr = dfs(ch,vis,adj);
            ans.push_back(chr);
        }
        return ans;
    }
};