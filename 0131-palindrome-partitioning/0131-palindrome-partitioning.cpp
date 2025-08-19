class Solution {
public:
    void func(int idx, string s, vector<vector<string>>& ans,
              vector<string>& curr) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (ispal(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                func(i + 1, s, ans, curr);
                curr.pop_back();
            }
        }
    }
    bool ispal(string s, int x, int y) {
        for (int i = x; i <= (x + y) / 2; i++) {
            if (s[i] != s[x + y - i])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        func(0, s, ans, curr);
        return ans;
    }
};