class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size(),ans=0;
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }
        for(int i=0;i<2;i++){
            if(i==1){
                for(int j=0;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        swap(fruits[j][k],fruits[k][j]);
                    }
                }
            }
            vector<int>prev(n,-1),curr(n,-1);
            prev[n-1]=fruits[0][n-1];
            for(int row=1;row<n-1;row++){
                for(int j=0;j<n;j++){
                    if(prev[j]<0)continue;
                    if(j>0){
                        curr[j-1]=max(curr[j-1],prev[j]+fruits[row][j-1]);
                    }if(j<n-1){
                        curr[j+1]=max(curr[j+1],prev[j]+fruits[row][j+1]);
                    }
                    curr[j]=max(curr[j],prev[j]+fruits[row][j]);
                }
                swap(prev,curr);
            }
            ans+=prev[n-1];
        }
        return ans;
    }
};