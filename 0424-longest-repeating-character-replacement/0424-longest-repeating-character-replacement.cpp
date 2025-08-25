class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=0;
        unordered_map<char,int>ump;
        int maxfreq=0;
        while(r<s.size()){
            ump[s[r]]++;
            maxfreq=max(maxfreq,ump[s[r]]);
            if(r-l+1-maxfreq > k){
                ump[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};