class Solution {
    bool solve(vector<double>&a){
        double eps=1e-6;
        int n=a.size();
        if(n==1)return fabs(a[0]-24.0)<eps;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                vector<double>b;
                for(int k=0;k<n;k++){
                    if(k!=i and k!=j){
                        b.push_back(a[k]);
                    }
                }
                b.push_back(a[i]+a[j]);
                if(solve(b))return true;
                b.back()=a[i]-a[j];
                if(solve(b))return true;
                b.back()=a[i]*a[j];
                if(solve(b))return true;
                if(fabs(a[j])>eps){
                    b.back()=a[i]/a[j];
                    if(solve(b))return true;
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>v;
        for(int x:cards){
            v.push_back(x);
        }
        return solve(v);
    }
};