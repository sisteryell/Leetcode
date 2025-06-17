const int mod=1e9+7;
typedef long long ll;
class Solution {
public:
    ll modInverse(ll a){
        ll res=1;
        ll power=mod-2;
        while(power){
            if(power&1)
                res=res*a%mod;
            a=a*a%mod;
            power>>=1;
        }
        return res;
    }
    int nCr(int n, int r){
        if(r>n)return 0;
        if(r==0 || r==n)return 1;
        ll res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)%mod;
            res=res*modInverse(i)%mod;
        }
        return (int)res;
    }
    ll powa(ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1)
                ans=(ans*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    int countGoodArrays(int n, int m, int k){
        int ans=(m*1ll*powa(m-1,n-(k+1)))%mod;
        ans=(ans*1ll*nCr(n-1,k))%mod; 
        return ans;
    }
};