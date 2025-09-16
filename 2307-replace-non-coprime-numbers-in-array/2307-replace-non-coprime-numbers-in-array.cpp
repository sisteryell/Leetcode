class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int idx=0,n=nums.size();
        int curr=nums[0];
        vector<int>st;
        while(idx<n){
            if(st.empty() || __gcd(st.back(),curr)==1){
                st.push_back(curr);
                idx++;
                if(idx>=n)break;
                curr=nums[idx];
            }else{
                int top=st.back();
                st.pop_back();
                curr=lcm(top,curr);
            }
        }
        return st;
    }
};