class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        set<char> st(str.begin(), str.end());
        int mx = num, mn = num;

        for (char ch : st) {
            for (char chr = '0'; chr <= '9'; chr++) {
                if (str[0] == ch && chr == '0') continue;
                string wd = str;
                replace(wd.begin(), wd.end(), ch, chr);
                int n = stoi(wd);
                mx = max(mx,n);
                mn = min(mn,n);
            }
        }
        return mx - mn;
    }
};