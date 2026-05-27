class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last(26,-1), first(26,-1);
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(islower(ch)){
                last[ch-'a']=i;
            }else{
                if(first[ch-'A']==-1){
                    first[ch-'A']=i;
                }
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(last[i]!=-1 and first[i]!=-1 and last[i]<first[i]){
                count++;
            }
        }
        return count;
    }
};