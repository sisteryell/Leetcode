class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2] or (i>0 and (s[i-1]==p[j-2] or p[j-2]=='.') and dp[i-1][j]);
                }
                else{
                    dp[i][j]=i>0 and dp[i-1][j-1] and (s[i-1]==p[j-1] or p[j-1]=='.');
                }
            }
        }
        return dp[n][m];
    }
};