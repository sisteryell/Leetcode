class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = prerequisites.size();
        vector<int>adj[numCourses];
        for(int i=0;i<V;i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indeg(numCourses,0);
        for(int i=0;i<numCourses;i++) {
            for(auto& x:adj[i])indeg[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) {
            if(indeg[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()) {
            int node=q.front();q.pop();
            cnt++;
            for(int& x:adj[node]) {
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        return cnt==numCourses;
    }
};