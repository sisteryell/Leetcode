class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        bool ans=true;
        for(char ch:s) {
            if(ch=='(' or ch=='{' or ch=='[') {
                st.push(ch);
            }else{
                if(st.empty())st.push(ch);
                else if(ch==')' and st.top()=='(') st.pop();
                else if(ch=='}' and st.top()=='{') st.pop();
                else if(ch==']' and st.top()=='[') st.pop();
                else st.push(ch);
            }
        }
        if(!st.empty())ans=false;
        return ans;
    }
};