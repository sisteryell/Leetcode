class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<vector<bool>> vis;
    int ans;
    int n,k;
    void dfs(int u, int count, int cost, string labels) {
        if(cost >= ans) {
            return;
        }
        if(u == n-1) {
            ans = min(ans, cost);
            return;
        }
        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int nextCount;
            if(labels[u] == labels[v]) {
                nextCount = count + 1;
            } else {
                nextCount = 1;
            }
            if(nextCount > k) {
                continue;
            }
            if(vis[v][nextCount]) {
                continue;
            }
            vis[v][nextCount] = true;
            dfs(v, nextCount, cost + w, labels);
            vis[v][nextCount] = false;
        } 
    }
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int ,int>>,
            greater<tuple<long long, int, int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while(!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();
            if(cost != dist[u][count]) {
                continue;
            }
            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                int nextCount;
                if(labels[u] == labels[v]) {
                    nextCount = count+1;
                } else {
                    nextCount = 1;
                }
                if(nextCount > k) {
                    continue;
                }
                long long newCost = cost + w;
                if(newCost < dist[v][nextCount]) {
                    dist[v][nextCount] = newCost;
                    pq.push({newCost, v, nextCount});
                }
            }
        }
        long long ans = LLONG_MAX;
        for(int count = 1; count <= k; count++) {
            ans = min(ans, dist[n - 1][count]);
        }
        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};