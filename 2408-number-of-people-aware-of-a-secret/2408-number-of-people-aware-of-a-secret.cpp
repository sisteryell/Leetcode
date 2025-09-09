class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n,-1);
        int mod=1000000007;
        function <int(int)> solve=[&](int idx)->int{
            if(idx+delay>n)return 1;
            if(dp[idx]!=-1)return dp[idx];
            int ans=1;
            for(int i=idx+delay;i<=min(n,idx+forget);i++){
                if(i==idx+forget){
                    ans-=1;
                    break;
                }
                ans=(ans+solve(i)%mod)%mod;
            }
            return dp[idx]=ans;
        };
        return solve(1);
    }
};