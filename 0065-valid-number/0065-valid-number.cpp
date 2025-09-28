class Solution {
public:
    bool isNumber(string s) {
        int start=s.find_first_not_of(" \t\n\r");
        int end=s.find_last_not_of(" \t\n\r");
        if(start==string::npos)return false;
        s=s.substr(start,end-start+1);
        bool dig=false,dot=false,exp=false,digafterexp=true;
        for(size_t i=0;i<s.length();i++){
            char ch=s[i];
            if(isdigit(ch)){
                dig=true;
                if(exp)digafterexp=true;
            }else if(ch=='+' or ch=='-'){
                if(i>0 and s[i-1]!='e' and s[i-1]!='E'){
                    return false;
                }
            }else if(ch=='.'){
                if(dot or exp){
                    return false;
                }
                dot=true;
            }else if(ch=='e' or ch=='E'){
                if(exp or !dig){
                    return false;
                }
                exp=true;
                digafterexp=false;
            }else{
                return false;
            }
        }
        return dig and digafterexp;
    }
};