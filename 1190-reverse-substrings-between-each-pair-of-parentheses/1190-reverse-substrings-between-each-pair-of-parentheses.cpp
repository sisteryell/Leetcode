class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char ch : s) {
            if (ch == ')') {
                string str = "";
                while(st.top() != '(') {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for(char chr : str) {
                    st.push(chr);
                }
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};