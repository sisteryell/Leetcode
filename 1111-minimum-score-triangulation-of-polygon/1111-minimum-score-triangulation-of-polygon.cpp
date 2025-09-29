class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=2;gap<n;gap++){
            for(int start=0;start<n-gap;start++){
                int end=start+gap;
                int curr=1<<30;
                for(int mid=start+1;mid<end;mid++){
                    int score=dp[start][mid]+dp[mid][end]+values[start]*values[mid]*values[end];
                    if(score<curr){
                        curr=score;
                    }
                }
                dp[start][end]=curr;
            }
        }
        return dp[0][n-1];
    }
};