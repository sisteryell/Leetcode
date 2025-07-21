class Solution {
public:
    string makeFancyString(string s) {
        vector<char>ans(s.begin(),s.end());
        char last=ans[0];
        int count=1,pos=1;
        for(int i=1;i<ans.size();i++) {
            if(ans[i]!=last) {
                last=ans[i];
                count=0;
            }
            if(++count > 2)continue;
            ans[pos++]=ans[i];
        }
        return string(ans.begin(),ans.begin()+pos);
    }
};