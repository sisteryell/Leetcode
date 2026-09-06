class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int m, int n) -> int {
            if (n < 0) return 1;
            if (m < 0) return 0;
            if (dp[m][n] != -1) return dp[m][n];
            if (s[m] == t[n]) return dp[m][n] = solve(m - 1, n - 1) + solve(m - 1, n);
            return dp[m][n] = solve(m - 1, n);
        };
        return solve(m - 1, n - 1);
    }
};