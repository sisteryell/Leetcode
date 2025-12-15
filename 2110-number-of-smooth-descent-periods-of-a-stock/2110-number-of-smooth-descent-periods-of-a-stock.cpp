    class Solution {
    public:
        long long getDescentPeriods(vector<int>& prices) {
            long long cnt=0,len=1;
            for(int i=0;i<prices.size();i++){
                if(i>0 and prices[i-1]-prices[i]==1)len++;
                else len=1;
                cnt+=len;
            }
            return cnt;
        }
    };