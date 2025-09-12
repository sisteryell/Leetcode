class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);
        set<pair<int,int>>st;
        for(auto road:roads){
            deg[road[0]]++;
            deg[road[1]]++;
            st.insert({road[0],road[1]});
            st.insert({road[1],road[0]});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rank=deg[i]+deg[j];
                if(st.find({i,j})!=st.end()){
                    rank--;
                }
                ans=max(ans,rank);
            }
        }
        return ans;
    }
};