class Solution {
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>&dp) {
        if(idx==0) {
            return amount%coins[0]==0;
        }
        if(dp[idx][amount]!=-1) dp[idx][amount];
        int np = solve(idx-1,amount,coins,dp);
        int p = 0;
        if(amount>=coins[idx]) p = solve(idx,amount-coins[idx],coins,dp);
        return dp[idx][amount] = p + np;
    }
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        // vector<vector<int>>dp(sz,vector<int>(amount+1,-1));
        // return solve(sz-1,amount,coins,dp);
        vector<vector<unsigned long long>>dp(sz,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<=amount;i++) {
            if(i%coins[0]==0)dp[0][i] = 1;
        }
        for(int idx=1;idx<sz;idx++) {
            for(int amt=0;amt<=amount;amt++) {
                unsigned long long np = dp[idx-1][amt];
                unsigned long long p = 0;
                if(amt>=coins[idx]) p = dp[idx][amt-coins[idx]];
                dp[idx][amt] = p+np;
            }
        }
        return dp[sz-1][amount];
    }
};