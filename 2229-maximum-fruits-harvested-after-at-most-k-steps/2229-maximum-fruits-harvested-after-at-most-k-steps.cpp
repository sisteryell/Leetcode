class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int>pos(n);
        vector<long long>ps(n+1,0);
        for(int i=0;i<n;i++) {
            pos[i]=fruits[i][0];
            ps[i+1]=ps[i]+fruits[i][1];
        }
        long long ans=0;
        int low=0;
        for(int high=0;high<n;high++) {
            long long pl=pos[low];
            long long ph=pos[high];
            long long cost=(ph-pl)+min(abs(startPos-pl),abs(startPos-ph));
            while(low<=high and cost>k){
                low++;
                if(low>high)break;
                pl=pos[low];
                cost=(ph-pl)+min(abs(startPos-pl),abs(startPos-ph));
            }
            if(low<=high){
                long long cf=ps[high+1]-ps[low];
                ans=max(ans,cf);
            }
        }
        return (int)ans;
    }
};