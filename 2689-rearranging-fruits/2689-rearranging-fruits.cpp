class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,long long>diff;
        for(int x:basket1){
            diff[x]++;
        }
        for(int x:basket2){
            diff[x]--;
        }
        int mn=INT_MAX;
        vector<int>temp;
        for(auto &[u,v]:diff){
            if(v&1)return -1;
            for(int i=0;i<abs(v)/2;i++){
                temp.push_back(u);
            }
            mn=min(mn,u);
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=0;i<temp.size()/2;i++) {
            ans+=min(temp[i],2*mn);
        }
        return ans;
    }
};