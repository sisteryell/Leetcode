class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > available, busy;

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }
        vector<int> ans(m);
        long long curr = 0;
        for(int i = 0; i < m; i++) {
            curr = max(curr, (long long)i);
            while(!busy.empty() and busy.top().first <= curr) {
                auto [freeTime, serverIndex] = busy.top();
                busy.pop();
                available.push({servers[serverIndex], serverIndex});
            }
            if(available.empty()) {
                curr = busy.top().first;
                while(!busy.empty() and busy.top().first <= curr) {
                    auto [freeTime, serverIndex] = busy.top();
                    busy.pop();
                    available.push({servers[serverIndex], serverIndex});
                }
            }
            auto [weight, serverIndex] = available.top();
            available.pop();
            ans[i] = serverIndex;
            busy.push({curr + tasks[i], serverIndex});
        }
        return ans;
    }
};