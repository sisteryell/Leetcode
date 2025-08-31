class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        function<int(int,int)>solve=[&](int i,int j)->int{
            if(i>=m or j>=n)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=0;
            if(nums1[i]==nums2[j]){
                ans=1+solve(i+1,j+1);
            }
            ans=max({ans,solve(i+1,j),solve(i,j+1)});
            return dp[i][j]=ans;
        };
        return solve(0,0);
    }
};