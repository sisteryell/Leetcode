class Solution {
    static bool compare( vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        sort(logs.begin(), logs.end(), compare);
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> ans(q);
        vector<int> freq(n + 1, 0);
        int left = 0, right = 0;
        int activeServer = 0;
        int L = logs.size();
        for(auto &query : sortedQueries) {
            int t = query.first;
            int index = query.second;
            int start = t - x;
            while(right < L and logs[right][1] <= t) {
                int server = logs[right][0];
                if(freq[server] == 0) {
                    activeServer++;
                }
                freq[server]++;
                right++;
            }
            while(left < right and logs[left][1] < start) {
                int server = logs[left][0];
                freq[server]--;
                if(freq[server] == 0) {
                    activeServer--;
                }
                left++;
            }
            ans[index] = n - activeServer;
        }
        return ans;
    }
};