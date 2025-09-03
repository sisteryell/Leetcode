class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>xs(n),ys(n);
        for(auto x:points){
            xs.push_back(x[0]);
            ys.push_back(x[1]);
        }
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());   
        sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());
        auto cx=[&](int x){
            return (int)(lower_bound(xs.begin(),xs.end(),x)-xs.begin())+1;
        };
        auto cy=[&](int y){
            return (int)(lower_bound(ys.begin(),ys.end(),y)-ys.begin())+1;
        };
        int mx=(int)xs.size(),my=(int)ys.size();
        vector<vector<int>>g(mx+1,vector<int>(my+1,0));
        vector<pair<int,int>>cp(n);
        for(int i=0;i<n;i++){
            int x=cx(points[i][0]),y=cy(points[i][1]);
            cp[i]={x,y};
            g[x][y]=1;
        }
        vector<vector<int>>pref(mx+1,vector<int>(my+1,0));
        for(int i=1;i<=mx;i++){
            for(int j=1;j<=my;j++){
                pref[i][j]=g[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
        auto query=[&](int x1,int y1,int x2,int y2){
            if(x2<x1 || y2<y1)return 0;
            return pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
        };
        int ans=0;
        for(int i=0;i<n;i++){
            int xa=cp[i].first,ya=cp[i].second;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int xb=cp[j].first,yb=cp[j].second;
                if(xa<=xb && ya>=yb && query(xa,yb,xb,ya)==2){
                    ans++;
                }
            }
        }
        return ans;
    }
};