class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int fa=0,fb=0,fl=0,fo=0,fn=0;
        for(char ch: text){
            if(ch=='a')fa++;
            else if(ch=='b')fb++;
            if(ch=='l')fl++;
            if(ch=='o')fo++;
            if(ch=='n')fn++;
        }
        fl=fl/2;fo=fo/2;
        return min({fa,fb,fl,fo,fn});
    }
};