class Solution {
    int solve(int n, int m, string& s1, string& s2, vector<vector<int>>&dp){
        if(n<0 or m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s1[n]==s2[m])return dp[n][m]=s1[n]+solve(n-1,m-1,s1,s2,dp);
        return dp[n][m]=max(solve(n-1,m,s1,s2,dp),solve(n,m-1,s1,s2,dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int sum1=0,sum2=0;
        for(char ch:s1)sum1+=ch;
        for(char ch:s2)sum2+=ch;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return sum1+sum2-2*solve(n-1,m-1,s1,s2,dp);
    }
};