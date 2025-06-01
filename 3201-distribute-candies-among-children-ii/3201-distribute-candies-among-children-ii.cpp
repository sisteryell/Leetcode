class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=(n+2ll)*(n+1)/2;
        for(int i=1;i<=3;i++){
            long long rem=n-1ll*i*(limit+1);
            if(rem<0)break;
            long long q=(rem+2)*(rem+1)/2;
            long long c=1;
            if(i<3)c=3;
            if(i&1)ans+=(-c*q);
            else ans+=(c*q);
        }
        return ans;
    }
};