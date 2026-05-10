class Solution {
    int n;
    vector<int>dp;
public:
    int solve(int i, vector<int>& nums, int l, int r){
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=-1e9;
        for(int j=i+1;j<n;j++){
            int diff=nums[j]-nums[i];
            if(l<=diff and diff<=r){
                int curr=1+solve(j,nums,l,r);
                maxi=max(maxi,curr);
            }
        }
        return dp[i]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        dp.resize(n,-1);
        int ans=solve(0,nums,-target,target);
        if(ans<0)return -1;
        return ans;
    }
};