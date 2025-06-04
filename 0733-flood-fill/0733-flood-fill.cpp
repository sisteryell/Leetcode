class Solution {
    void dfs(int row, int col, int color, int originalcolor, vector<vector<int>>& image){
        int m = image.size(), n = image[0].size();
        image[row][col] = color;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow = row+drow[i], ncol = col+dcol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and image[nrow][ncol]==originalcolor){
                dfs(nrow,ncol,color,originalcolor,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor = image[sr][sc];
        if(color!=originalcolor)dfs(sr,sc,color,originalcolor,image);
        return image;
    }
};