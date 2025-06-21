class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>freq;
        for(char ch:word) {
            freq[ch]++;
        }
        vector<int>v;
        for(auto x:freq) {
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int ans=1e9;
        for(int i=0;i<n;i++) {
            int r=v[i]+k;
            int tot=v[i];
            for(int j=i+1;j<n;j++) {
                if(v[j]>r) tot+=r;
                else tot+=v[j];
            }
            int remain=word.size()-tot;
            ans=min(ans,remain);
        }
        return ans;
    }
};