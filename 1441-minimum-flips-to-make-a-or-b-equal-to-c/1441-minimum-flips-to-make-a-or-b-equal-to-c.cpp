class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(a or b or c){
            if(c&1){
                if(!(a&1) and !(b&1))flip++;
            }else{
                if(a&1)flip++;
                if(b&1)flip++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};