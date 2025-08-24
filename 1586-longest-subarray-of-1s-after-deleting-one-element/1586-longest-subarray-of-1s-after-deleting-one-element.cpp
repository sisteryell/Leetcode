class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0,cnt0=0,ans=0;
        while(right<nums.size()){
            if(nums[right]==0)cnt0++;
            while(cnt0>1){
                if(nums[left]==0)cnt0--;
                left++;
            }
            ans=max(ans,right-left);
            right++;
        }
        return ans;
    }
};