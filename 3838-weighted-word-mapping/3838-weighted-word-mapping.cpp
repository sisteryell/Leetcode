class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string& wd: words){
            long long sum=0;
            for(char ch: wd){
                sum+=weights[ch-'a'];
            }
            ans.push_back('z'-(sum%26));
        }
        return ans;
    }
};