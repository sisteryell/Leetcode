class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0,num=0,len=1;
        while(n){
            num+=(n%10)*len;
            if(n%10!=0)len=len*10;
            sum+=n%10;
            n/=10;
        }
        return (long long)sum*num;
    }
};