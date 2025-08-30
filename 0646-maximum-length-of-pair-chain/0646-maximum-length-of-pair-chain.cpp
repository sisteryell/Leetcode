class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        function<int(int,int)>lis=[&](int pidx,int idx)->int{
            if(idx==n)return 0;
            if(pidx!=-1 && dp[pidx][idx]!=-1){
                return dp[pidx][idx];
            }
            int pick=0;
            if(pidx==-1 or pairs[idx][0]>pairs[pidx][1]){
                pick=1+lis(idx,idx+1);
            }
            int not_pick=lis(pidx,idx+1);
            if(pidx!=-1){
                dp[pidx][idx]=max(pick,not_pick);
            }
            return max(pick, not_pick);
        };
        return lis(-1,0);       
    }
};