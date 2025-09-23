class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int m=words[0].size();
        int n=s.size();
        int ws=words.size()*m;
        unordered_map<string,int>ump;
        for(int i=0;i<words.size();i++){
            ump[words[i]]++;
        }
        auto solve=[&](string st)->bool{
            unordered_map<string,int>mpp=ump;
            for(int i=0;i<st.size();i+=m){
                string str=st.substr(i,m);
                if(mpp.find(str)!=mpp.end()){
                    if(--mpp[str]==-1)return false;
                }else{
                    return false;
                }
            }
            return true;
        };
        int idx=0;
        while(idx+ws<=n){
            if(solve(s.substr(idx,ws))){
                ans.push_back(idx);
            }
            idx++;
        }
        return ans;
    }
};