class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=-1e9;
        int n=energy.size();
        vector<int>dp(n,-1);
        function<int(int)>func=[&](int idx)->int{
            if(idx>=energy.size())return -1e9;
            if(dp[idx]!=-1)return dp[idx];
            int take=energy[idx];
            if(k+idx<energy.size()){
                take+=func(idx+k);
            }
            return dp[idx]=take;
        };
        for(int i=0;i<n;i++){
            ans=max(ans,func(i));
        }
        return ans;
    }
};