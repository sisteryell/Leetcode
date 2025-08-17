class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 or n>=k+maxPts-1)return 1.0;
        vector<double>dp(n+1);
        dp[0]=1.0;
        double s=1.0;
        for(int i=1;i<=n;i++){
            dp[i]=s/maxPts;
            if(i<k)s+=dp[i];
            if(i-maxPts>=0)s-=dp[i-maxPts];
        }
        double ans=0;
        for(int i=k;i<=n;i++){
            ans+=dp[i];
        }
        return ans;
    }
};