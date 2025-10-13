class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>ans,temp(words);
        for(int i=0;i<n;i++){
            sort(words[i].begin(),words[i].end());
        }
        ans.push_back(temp[0]);
        for(int i=1;i<n;i++){
            if(words[i]!=words[i-1]){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};