class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,num=0;
        string str=to_string(n);
        string wd="";
        for(char ch: str){
            if(ch!='0'){
                wd=wd+ch;
                sum+=ch-'0';
            }
        }
        if(wd=="")return 0;
        num=stoi(wd);
        return sum*num;
    }
};