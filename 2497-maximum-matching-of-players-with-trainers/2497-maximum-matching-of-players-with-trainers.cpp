class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n=players.size(),m=trainers.size();
        int i=0,j=0,ans=0;
        while(i<n and j<m) {
            if(players[i]<=trainers[j]) {
                ans++;
                i++;
                j++;
            }else {
                j++;
            }
        }
        return ans;
    }
};