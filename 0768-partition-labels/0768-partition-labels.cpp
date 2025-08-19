class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> um;
        int j=0,start=0,n=s.size();
        for(int i=0;i<n;i++){
            um[s[i]]=i;
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            j= max(j,um[s[i]]);
            if(i==j){
                v.push_back(j-start+1);
                start=i+1;
            }
        }
        return v;
    }
};