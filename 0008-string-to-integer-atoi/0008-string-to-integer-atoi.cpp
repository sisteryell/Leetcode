class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0,sgn=1;
        long ans=0;
        while(i<n and s[i]==' ')i++;
        if(i<n and (s[i]=='-' or s[i]=='+')){
            if(s[i]=='-')sgn=-1;
            i++;
        }
        while(i<n and isdigit(s[i])){
            int digit=s[i]-'0';
            if(ans>(INT_MAX - digit)/10){
                return sgn==1 ? INT_MAX : INT_MIN;
            }
            ans=ans*10+digit;
            i++;
        }
        return (int)(ans*sgn);
    }
};