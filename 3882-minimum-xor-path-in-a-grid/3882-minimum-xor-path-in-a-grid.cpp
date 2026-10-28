class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int maxx=1024;
        int m=grid.size(),n=grid[0].size();
        vector<bitset<maxx>>prev(n),cur(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bitset<maxx>nxt;
                if(i==0 and j==0){
                    nxt.set(grid[0][0]);
                }else{
                    bitset<maxx>reach;
                    if(i>0)reach=reach|prev[j];
                    if(j>0)reach=reach|cur[j-1];
                    int v=grid[i][j];
                    for(int x=0;x<maxx;x++){
                        if(reach.test(x)){
                            nxt.set(x^v);
                        }
                    }
                }
                cur[j]=nxt;
            }
            prev=cur;
            for(auto &b: cur){
                b.reset();
            }
        }
        for(int x=0;x<maxx;x++){
            if(prev[n-1].test(x))return x;
        }
        return -1;
    }
};