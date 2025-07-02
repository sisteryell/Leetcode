class Solution {
    int result(vector<int>& nums, int divisor) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=(nums[i]/divisor);
            if(nums[i]%divisor)sum++;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high) {
            int mid=low+(high-low)/2;
            int sum=result(nums,mid);
            if(sum<=threshold)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};