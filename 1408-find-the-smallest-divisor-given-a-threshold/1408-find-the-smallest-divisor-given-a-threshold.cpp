class Solution {
    int sumation(vector<int>&nums,int mid) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]/mid;
            if(nums[i]%mid)sum++;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=sumation(nums,mid);
            if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};