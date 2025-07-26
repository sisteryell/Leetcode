class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posidx=0,negidx=1;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posidx]=nums[i];
                posidx+=2;
            }
            else {
                ans[negidx]=nums[i];
                negidx+=2;
            }
        }
        return ans;
    }
};