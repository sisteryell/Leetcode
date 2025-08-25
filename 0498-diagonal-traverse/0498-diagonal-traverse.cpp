class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>ans(m*n);
        int r=0,c=0;
        for(int i=0;i<m*n;i++){
            ans[i]=mat[r][c];
            if((r+c)&1){
                if(r==m-1)c++;
                else if(c==0)r++;
                else {r++;c--;}
            }else{
                if(c==n-1)r++;
                else if(r==0)c++;
                else {r--;c++;}
            }
        }
        return ans;
    }
};