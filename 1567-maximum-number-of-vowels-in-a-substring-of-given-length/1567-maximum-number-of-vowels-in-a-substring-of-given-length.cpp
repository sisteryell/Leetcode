class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0,count=0;
        unordered_set<char>st={'a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                count++;
            }
            if(i>=k and st.count(s[i-k])){
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};