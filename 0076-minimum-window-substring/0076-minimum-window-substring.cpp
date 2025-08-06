class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch:t)mp[ch]++;
        int sind=0;
        int len=INT_MAX;
        int count=0;
        int i=0,j=0,n=s.size();
        int target=t.size();
        while(i<n and j<n) {
            char ch=s[j];
            if(mp[ch]>0)count++;
            mp[ch]--;
            while(count==target){
                if(j-i+1 < len){
                    sind=i;
                    len=j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count--;
                    i++;
                    break;
                }
                i++;
            }
            j++;
        }
        if(len==INT_MAX)return "";
        return s.substr(sind,len);
    }
};