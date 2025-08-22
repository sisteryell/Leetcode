class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int mnr=m,mxr=-1;
        int mnc=n,mxc=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mnr=min(mnr, i);
                    mxr=max(mxr,i);
                    mnc=min(mnc,j);
                    mxc=max(mxc,j);
                }
            }
        }
        return (mxr-mnr+1)*(mxc-mnc+1);
    }
};