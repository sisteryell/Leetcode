class Solution {
    bool check(string &s, string &t, int k) {
        int cnt=0,i=0;
        for(char ch:t) {
            if(ch==s[i]){
                if(++i==s.size()) {
                    i=0;
                    if(++cnt==k)return true;
                }
            }
        }
        return false;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        queue<string>q;
        q.push("");
        while(!q.empty()) {
            string fr=q.front();q.pop();
            for(char ch='a';ch<='z';ch++) {
                string str=fr+ch;
                if(check(str,s,k)) {
                    ans=str;
                    q.push(str);
                }
            }
        }
        return ans;
    }
};