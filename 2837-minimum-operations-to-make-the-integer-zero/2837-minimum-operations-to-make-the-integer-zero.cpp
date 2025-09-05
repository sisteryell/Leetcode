class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long x=num1-1ll*num2*i;
            if(x<i)return -1;
            if(__builtin_popcountll(x)<=i)return i;
        }
        return -1;
    }
};