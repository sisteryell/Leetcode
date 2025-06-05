class Solution {
    int solve(int idx, int amount, bool& flag, vector<int>& coins, vector<vector<int>>&dp) {
        if(idx==0) {
            if(amount%coins[0])return 1e8;
            flag=true;
            return amount/coins[0];
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int np = solve(idx-1,amount,flag,coins,dp);
        int p = INT_MAX;
        if(amount>=coins[idx]) p = 1 + solve(idx,amount-coins[idx],flag,coins,dp);
        return dp[idx][amount] = min(p,np);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        bool flag=false;
        int no_of_coins = solve(n-1,amount,flag,coins,dp);
        if(flag)return no_of_coins;
        else return -1;
    }
};