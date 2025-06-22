class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int idx=0,sz=s.size();
        vector<string> ans;
        string wd="";
        while(idx<sz) {
            int n=wd.size();
            if(n==k) {
                ans.push_back(wd);
                wd="";
            }
            wd+=s[idx++];
        }
        if(wd.size()<k) {
            int n=wd.size();
            for(int i=n;i<k;i++)wd+=fill;
        }
        ans.push_back(wd);
        return ans;
    }
};