class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,maxx=1;
        int n=s.size();
        for(int i=0;i<n;i++) {
            int left=i,right=i;
            while(left>=0 && right<n) {
                if(s[left]!=s[right])break;
                int len=right-left+1;
                if(maxx<len) {
                    maxx=len;
                    st=left;
                }
                left--;
                right++;
            }
        }
        for(int i=0;i<n;i++) {
            int left=i,right=i+1;
            while(left>=0 && right<n) {
                if(s[left]!=s[right])break;
                int len=right-left+1;
                if(maxx<len) {
                    maxx=len;
                    st=left;
                }
                left--;right++;
            }
        }
        return s.substr(st,maxx);
    }
};