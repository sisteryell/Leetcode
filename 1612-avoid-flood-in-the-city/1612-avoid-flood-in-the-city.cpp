class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>lakes;
        set<int>dry;
        int n=rains.size();
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                if(!lakes.empty()){
                    dry.insert(i);
                }
                continue;
            }
            if(lakes.find(rains[i])==lakes.end()){
                lakes[rains[i]]=i;
                ans[i]=-1;
                continue;
            }
            if(dry.empty())return {};
            else{
                auto x=dry.begin();
                while(x!=dry.end() and *x<lakes[rains[i]]){
                    x++;
                }
                if(x==dry.end())return {};
                ans[*x]=rains[i];
                ans[i]=-1;
                lakes[rains[i]]=i;
                dry.erase(x);
            }
        }
        return ans;

    }
};