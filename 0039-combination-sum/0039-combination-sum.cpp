class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>>dp(target+1);
        dp[0].push_back(vector<int>());
        for(int c:candidates){
            for(int t=c;t<=target;t++){
                for(auto &comb:dp[t-c]){
                    vector<int> newComb = comb;
                    newComb.push_back(c);
                    dp[t].push_back(newComb);
                }
            }
        }
        return dp[target];
    }
};