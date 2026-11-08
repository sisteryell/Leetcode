class Solution {
    vector<vector<int>> dp;
    int find(int k, int n) {
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = 1e9;
        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int br = find(k - 1, mid - 1);
            int nb = find(k, n - mid);
            ans = min(ans, 1 + max(br, nb));
            if(br < nb) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return dp[k][n] = ans;
    }
public:
    int superEggDrop(int k, int n) {
        dp.assign(k+1, vector<int>(n+1, -1));
        return find(k, n);
    }
};