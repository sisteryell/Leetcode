class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        long long cur=-1e18;
        int ans=0;
        for(auto &x:points){
            if(cur<x[0]){
                ans++;
                cur=x[1];
            }
        }
        return ans;
    }
};