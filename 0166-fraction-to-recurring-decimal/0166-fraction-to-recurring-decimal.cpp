#define ll long long
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        string ans;
        if((numerator<0) ^ (denominator<0)){
            ans+="-";
        }
        ll num=llabs((ll)numerator);
        ll den=llabs((ll)denominator);
        ans+=to_string(num/den);
        ll rem=num%den;
        if(rem==0)return ans;
        ans+=".";
        unordered_map<ll,int>ump;
        while(rem!=0){
            if(ump.count(rem)){
                ans.insert(ump[rem],"(");
                ans+=")";
                break;
            }
            ump[rem]=ans.size();
            rem*=10;
            ans+=to_string(rem/den);
            rem%=den;
        }
        return ans;
    }
};