class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>seen(3,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            seen[s[i]-'a']=i;
            count+=*min_element(seen.begin(),seen.end())+1;
        }
        return count;
    }
};