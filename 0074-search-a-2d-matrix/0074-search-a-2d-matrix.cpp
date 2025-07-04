class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0,high=m*n-1;
        bool ans=false;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]==target){ans=true;break;}
            else if(matrix[row][col]<target)low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};