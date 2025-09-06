class Solution {
    long long solve(long long n){
        if(n<=0)return 0;
        long long ans=0,b=1,s=1;
        while(b<=n){
            long long cnt=min(n,b*4-1)-b+1;
            ans+=cnt*s;
            b*=4;
            s++;
        }
        return ans;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto &x:queries){
            long long l=x[0],r=x[1];
            long long tot=solve(r)-solve(l-1);
            ans+=(tot+1)/2;
        }
        return ans;
    }
};