class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustee(n+1,0),trusted(n+1,0);
        for(int i=0;i<trust.size();i++){
            trustee[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(trustee[i]==0 and trusted[i]==n-1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};