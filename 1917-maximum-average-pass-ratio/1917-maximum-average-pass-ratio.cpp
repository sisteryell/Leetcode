class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        auto func=[&](int p,int t)->double{
            return (double)(p+1)/(t+1)-(double)p/t;
        };
        priority_queue<tuple<double,int,int>>pq;
        for(vector<int>x : classes){
            pq.emplace(func(x[0],x[1]),x[0],x[1]);
        }
        while(extraStudents!=0){
            auto [a,b,c]=pq.top();
            pq.pop();
            b++;c++;
            pq.emplace(func(b,c),b,c);
            extraStudents--;
        }
        double sum=0;
        while(!pq.empty()){
            auto [a,b,c]=pq.top();
            pq.pop();
            sum+=(double)b/c;
        }
        return sum/n;
    }
};