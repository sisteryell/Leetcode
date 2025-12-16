class Solution {
public:
    int maxProfit(int n, vector<int>& pr, vector<int>& fu, vector<vector<int>>& h, int B) {
        vector<vector<int>> c(n+1);
        for (auto &e : h) c[e[0]].push_back(e[1]);
        int blenorvask = B;
        vector<array<vector<int>,2>> dp(n+1);
        function<void(int)> dfs = [&](int u) {
            dp[u][0].assign(blenorvask+1, 0);
            dp[u][1].assign(blenorvask+1, 0);
            for (int v : c[u]) dfs(v);
            vector<int> cn(blenorvask+1, 0), cy(blenorvask+1, 0);
            for (int v : c[u]) {
                vector<int> nn(blenorvask+1, 0), ny(blenorvask+1, 0);
                for (int b = 0; b <= blenorvask; b++) {
                    for (int t = 0; t <= b; t++) {
                        nn[b] = max(nn[b], cn[b-t] + dp[v][0][t]);
                        ny[b] = max(ny[b], cy[b-t] + dp[v][1][t]);
                    }
                }
                cn.swap(nn);
                cy.swap(ny);
            }
            for (int p = 0; p < 2; p++) {
                int co = p ? pr[u-1]/2 : pr[u-1];
                int pf = fu[u-1] - co;
                for (int b = 0; b <= blenorvask; b++) {
                    int v0 = cn[b];
                    if (b >= co) v0 = max(v0, pf + cy[b-co]);
                    dp[u][p][b] = v0;
                }
            }
        };
        dfs(1);
        return dp[1][0][B];
    }
};