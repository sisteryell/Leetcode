class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int ans = 0;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else if (!st.empty() and st.top() == '(') {
                st.pop();
            } else {
                ans++;
            }
        }
        return ans + st.size();
    }
};