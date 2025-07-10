class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        int T=eventTime;
        vector<long long>g(n+1);
        g[0]=startTime[0];
        for(int i=1;i<n;i++){
            g[i]=(long long)startTime[i]-endTime[i-1];
        }
        g[n]=(long long)T-endTime[n-1];
        multiset<long long>ms;
        for(int i=0;i<=n;i++){
            ms.insert(g[i]);
        }
        long long ans=*ms.rbegin();
        for(int j=0;j<n;j++){
            long long d=(long long)endTime[j]-startTime[j];
            long long a=g[j];
            long long b=g[j+1];
            auto it=ms.find(a);
            ms.erase(it);
            it=ms.find(b);
            ms.erase(it);
            long long H=0;
            if(!ms.empty()){
                H=*ms.rbegin();
            }
            long long M=a+b+d;
            long long cur;
            if(H>=d){
                if(M>H){
                    cur=M;
                }else{
                    cur=H;
                }
            }else{
                long long x=M-d;
                if(x>H){
                    cur=x;
                }else{
                    cur=H;
                }
            }
            if(cur>ans){
                ans=cur;
            }
            ms.insert(a);
            ms.insert(b);
        }
        return (int)ans;
    }
};
