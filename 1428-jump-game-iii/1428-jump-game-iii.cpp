class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int idx=q.front();q.pop();
            if(arr[idx]==0)return true;
            if(idx+arr[idx]<n and !vis[idx+arr[idx]]){
                q.push(idx+arr[idx]);
                vis[idx+arr[idx]]=1;
            }
            if(idx-arr[idx]>=0 and !vis[idx-arr[idx]]){
                q.push(idx-arr[idx]);
                vis[idx-arr[idx]]=1;
            }
        }
        return false;
    }
};