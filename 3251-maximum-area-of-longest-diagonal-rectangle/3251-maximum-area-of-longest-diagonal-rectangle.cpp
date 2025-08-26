class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        double maxDiag=0;
        for(auto& rect:dimensions){
            int length=rect[0],width=rect[1];
            double diag=hypot(length,width);
            int area=length*width;
            if(diag>maxDiag){
                maxDiag=diag;
                maxArea=area;
            }else if(diag==maxDiag) {
                maxArea=max(maxArea, area);
            }
        }
        return maxArea;
    }
};
