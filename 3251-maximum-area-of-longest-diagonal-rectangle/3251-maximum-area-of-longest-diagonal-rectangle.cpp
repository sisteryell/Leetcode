class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0,n=dimensions.size();
        double max_diag=0.0;
        for(int i=0;i<n;i++){
            double diag=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if(max_diag<diag){
                max_diag=diag;
                ans=dimensions[i][0]*dimensions[i][1];
            }
            else if(max_diag==diag){
                ans=max(ans,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return ans;
    }
};