class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);
        vector<int> previous(n, -1);
        stack<pair<int,bool>> st;
        st.push({0,true});
        while(!st.empty()) {
            int node = st.top().first;
            bool flag = st.top().second;
            st.pop();
            int ch = s[node] - 'a';
            if(flag) {
                if(node != 0 && lastSeen[ch] != -1) {
                    newParent[node] = lastSeen[ch];
                }
                previous[node] = lastSeen[ch];
                lastSeen[ch] = node;
                st.push({node, false});
                for(int child : adj[node]) {
                    st.push({child, true});
                }
            } else {
                lastSeen[ch] = previous[node];
            }
        }
        vector<vector<int>> finalAdj(n);
        for(int i = 1; i < n; i++) {
            finalAdj[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        vector<int> order;
        stack<int> dfs;
        dfs.push(0);
        while(!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();
            order.push_back(node);
            for(int child : finalAdj[node]) {
                dfs.push(child);
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int node = order[i];
            if(newParent[node] != -1) {
                ans[newParent[node]] += ans[node];
            }
        }
        return ans;
    }
};