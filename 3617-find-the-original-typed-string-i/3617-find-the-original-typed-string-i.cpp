class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(),ans=0;
        for(int i=0;i<n-1;) {
            int j=i+1;
            while(word[i]==word[j]){
                ans++;
                j++;
            }
            i=j;
        }
        return ans+1;
    }
};