class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1,ans=1e9;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]==nums[mid] and nums[mid]==nums[hi]){
                ans=min(ans,nums[lo]);
                lo++,hi--;
                continue;
            }
            if(nums[lo]<=nums[mid]){
                ans=min(ans,nums[lo]);
                lo=mid+1;
            }else{
                ans=min(ans,nums[mid]);
                hi=mid-1;
            }
        }
        return ans;
    }
};