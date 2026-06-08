class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size(), j=0, k=n-1;
        vector<int> ans(n);
        for(int num: nums){
            if(num<pivot){
                ans[j]=num;
                j++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==pivot){
                ans[j]=nums[i];
                j++;
            }else if(nums[i]>pivot){
                ans[k]=nums[i];
                k--;
            }
        }
        return ans;
    }
};