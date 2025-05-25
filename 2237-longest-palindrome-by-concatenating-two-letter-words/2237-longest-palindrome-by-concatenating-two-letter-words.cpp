class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        int n=w.size();
        unordered_map<string,int>f;
        for(auto& s:w)f[s]++;
        int ans=0;
        bool mid=false;
        for(auto& [s,c]:f){
            string t={s[1],s[0]};
            if(s<t && f.count(t)){
                int m=min(c,f[t]);
                ans+=m*4;
            }
        }
        for(auto& [s,c]:f){
            if(s[0]==s[1]){
                ans+=(c/2)*4;
                if(c&1)mid=true;
            }
        }
        if(mid)ans+=2;
        return ans;
    }
};
