class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>ump;
        int l=0,r=0,ans=0,n=s.length();
        while(r<n){
            if(ump.find(s[r])!=ump.end()){
                l=max(l,ump[s[r]]+1);
            }
            ans=max(ans,r-l+1);
            ump[s[r]]=r;
            r++;
        }
        return ans;
    }
};