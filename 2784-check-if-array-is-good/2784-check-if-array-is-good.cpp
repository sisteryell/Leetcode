class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return false;
        for(int i=0;i<n;i++){
            while(nums[i]<n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]-1!=i)return false;
        }
        return nums[n-1]==n-1;
    }
};