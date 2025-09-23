class Solution {
public:
    int calculate(string s) {
        int ans=0,sgn=1,num=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }else if(ch=='+'){
                ans+=sgn*num;
                num=0;
                sgn=1;
            }else if(ch=='-'){
                ans+=sgn*num;
                num=0;
                sgn=-1;
            }else if(ch=='('){
                st.push(ans);
                st.push(sgn);
                ans=0;
                sgn=1;
            }else if(ch==')'){
                ans+=sgn*num;
                num=0;
                ans*=st.top();st.pop();
                ans+=st.top();st.pop();
            }
        }
        ans+=sgn*num;
        return ans;
    }
};