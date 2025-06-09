class Solution {
    int solve(long a, long b, long& n) {
        int x = 0;
        while(a<=n) {
            x+=min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return x;
    }
public:
    int findKthNumber(long n, int k) {
        long num = 1;
        for(int i=1;i<k;) {
            int req = solve(num,num+1,n);
            if(i+req <= k) {
                i+=req;
                num++;
            }else{
                i++;
                num*=10;
            }
        }
        return num;
    }
};