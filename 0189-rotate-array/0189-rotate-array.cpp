class Solution {
    void rotate(int s, int l, vector<int>&nums) {
        while(s<=l) {
            int temp=nums[s];
            nums[s]=nums[l];
            nums[l]=temp;
            s++;l--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        rotate(n-k,n-1,nums);
        rotate(0,n-k-1,nums);
        rotate(0,n-1,nums);
    }
};