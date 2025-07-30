class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,n=nums.size();
        int a=INT_MIN,b=INT_MIN;
        for(int x:nums){
            if(cnt1==0 and b!=x){
                cnt1=1;
                a=x;
            }else if(cnt2==0 and a!=x){
                cnt2=1;
                b=x;
            }
            else if(a==x)cnt1++;
            else if(b==x)cnt2++;
            else {cnt1--;cnt2--;}
        }
        vector<int>ans;
        cnt1=0,cnt2=0;
        for(int x:nums){
            if(x==a)cnt1++;
            if(x==b)cnt2++;
        }
        if(cnt1>n/3)ans.push_back(a);
        if(cnt2>n/3)ans.push_back(b);
        return ans;
    }
};