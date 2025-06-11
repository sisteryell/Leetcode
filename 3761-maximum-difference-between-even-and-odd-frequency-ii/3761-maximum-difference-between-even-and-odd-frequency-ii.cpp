class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;
        for(int i=0;i<=4;i++) {
            for(int j=0;j<=4;j++) {
                if(i==j)continue;
                vector<int>s1(n+1),s2(n+1);
                for(int l=1;l<=n;l++) {
                    s1[l] = s1[l-1]+(s[l-1]-'0'==i);
                    s2[l] = s2[l-1]+(s[l-1]-'0'==j);
                }
                int g[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int m = 0;
                for(int l=k;l<=n;l++) {
                    while(l-m>=k and s1[l]>s1[m] and s2[l]>s2[m]) {
                        int pi = s1[m]%2;
                        int pj = s2[m]%2;
                        g[pi][pj] = max(g[pi][pj],s2[m]-s1[m]);
                        m++;
                    }
                    int pi = s1[l]%2;
                    int pj = s2[l]%2;
                    int need = g[1-pi][pj];
                    if(need!=INT_MIN) ans = max(ans,s1[l]-s2[l]+need);
                }
            }
        }
        if(ans==INT_MIN)return -1;
        return ans;
    }
};