class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn=nums[0];
        int ans=0;
        for(int x:nums) {
            ans=max(ans,x-mn);
            mn=min(mn,x);
        }
        if(ans==0)return -1;
        return ans;
    }
};