class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string&)> solve = [&](int open, int close, string &s) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }
            if (open < n) {
                s.push_back('(');
                solve(open + 1, close, s);
                s.pop_back();
            }
            if (close < open) {
                s.push_back(')');
                solve(open, close + 1, s);
                s.pop_back();
            }
        };
        string s;
        solve(0, 0, s);
        return ans;
    }
};