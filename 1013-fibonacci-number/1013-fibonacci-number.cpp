class Solution {
vector<int>dp;
public:
    Solution():dp(31,-1){}
    int fib(int n) {
        if(n==0 or n==1)return n;
        if(dp[n]!=-1)return dp[n];
        return fib(n-1)+fib(n-2);
    }
};