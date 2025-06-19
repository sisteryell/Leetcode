class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size(),mn=nums[0];
        for(int i=0;i<n;i++) {
            if(nums[i]-mn>k) {
                ans++;
                mn=nums[i];
            }
        }
        return ans+1;
    }
};