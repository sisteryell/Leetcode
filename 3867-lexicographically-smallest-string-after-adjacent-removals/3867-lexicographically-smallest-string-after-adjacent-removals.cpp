class Solution {
public:
    string lexicographicallySmallestString(string s) {
        int n=s.size();
        vector<vector<bool>>rem(n,vector<bool>(n,false));
        auto solve=[&](char a, char b)->bool{
            int diff=abs(a-b);
            return diff==1 or diff==25;
        };
        for(int len=2;len<=n;len+=2){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(solve(s[i],s[j])){
                    if(len==2 or rem[i+1][j-1]){
                        rem[i][j]=true;
                        continue;
                    }
                }
                for(int k=i+1;k<j;k+=2){
                    if(rem[i][k] and rem[k+1][j]){
                        rem[i][j]=true;
                        break;
                    }
                }
            }
        }
        vector<string>dp(n+1,"");
        for(int i=n-1;i>=0;i--){
            dp[i]=s[i]+dp[i+1];
            for(int k=i+1;k<n;k++){
                if(solve(s[i],s[k])){
                    if(k==i+1 or rem[i+1][k-1]){
                        if(dp[k+1]<dp[i]){
                            dp[i]=dp[k+1];
                        }
                    }
                }
            }
        }
        return dp[0];
    }
};