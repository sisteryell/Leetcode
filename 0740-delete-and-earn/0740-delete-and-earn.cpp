class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>dp(10001,0);
        for(int x:nums){
            dp[x]+=x;
        }
        int p=0,np=0;
        for(int i=0;i<10001;i++){
            int pi=np+dp[i];
            int npi=max(np,p);
            p=pi;
            np=npi;
        }
        return max(p,np);
    }
};