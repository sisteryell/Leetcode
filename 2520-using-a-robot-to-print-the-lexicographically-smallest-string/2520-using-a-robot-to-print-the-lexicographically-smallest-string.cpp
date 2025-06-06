class Solution {
    char func(vector<int>& f) {
        for(int i=0;i<26;i++) {
            if(f[i]) return 'a' + i;
        }
        return 'a';
    }
public:
    string robotWithString(string s) {
        stack<char>st;
        string t = "";
        vector<int> f(26);
        for(char ch : s) {
            f[ch - 'a']++;
        }
        for(char ch : s) {
            st.push(ch);
            f[ch - 'a']--;
            while(!st.empty() and st.top() <= func(f)) {
                t += st.top();
                st.pop();
            }
        }
        while(!st.empty()) {
            t += st.top();
            st.pop();
        }
        return t;
    }
};