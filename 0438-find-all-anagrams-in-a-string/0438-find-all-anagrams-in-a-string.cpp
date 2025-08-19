class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26);
        int m=p.length();
        int n=s.length();
        for(auto &ch:p){
            freq[ch-'a']++;
        }
        int len=0;
        int prev=0;
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']-- >0) len++;
            while(freq[s[i]-'a']<0){
                if(++freq[s[prev]-'a'] >0) len--;
                prev++;
            }
            if(len==m){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};