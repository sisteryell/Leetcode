class Solution {
public:
    int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<long long> power(n+1,1);
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*10LL)%MOD;
        }
        vector<int>digitSum(n+1,0);
        vector<long long> value(n+1,0);
        vector<int>cnt(n+1,0);
        for(int i=0;i<n;i++){
            int d=s[i]-'0';
            digitSum[i+1]=digitSum[i]+d;
            if(d==0){
                value[i+1]=value[i];
                cnt[i+1]=cnt[i];
            }else{
                value[i+1]=(value[i]*10LL+d)%MOD;
                cnt[i+1]=cnt[i]+1;
            }
        }
        vector<int> ans;
        for(auto &q: queries){
            int l=q[0];
            int r=q[1]+1;
            int sum=digitSum[r]-digitSum[l];
            long long left=(value[l]*power[cnt[r]-cnt[l]])%MOD;
            long long num=(value[r]-left+MOD)%MOD;
            ans.push_back((num*sum)%MOD);
        }
        return ans;
    }
};