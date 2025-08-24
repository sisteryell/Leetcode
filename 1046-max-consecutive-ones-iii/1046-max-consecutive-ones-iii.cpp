class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0,ans=0;
        while(right<n){
            if(nums[right]==0 and k==0){
                while(nums[left]!=0)left++;
                left++;
            }else if(nums[right]==0 and k>0)k--;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};