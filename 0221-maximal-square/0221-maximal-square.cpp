class Solution {
public:
    int solve(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>>&dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(matrix,i,j+1,maxi,dp);
        int dgnl=solve(matrix,i+1,j+1,maxi,dp);
        int down=solve(matrix,i+1,j,maxi,dp);

        if(matrix[i][j]=='1'){
            int ans=1+min(right,min(dgnl,down));
            maxi=max(maxi,ans);
            return dp[i][j]=ans;
        }
        else {
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,-1));
        solve(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};