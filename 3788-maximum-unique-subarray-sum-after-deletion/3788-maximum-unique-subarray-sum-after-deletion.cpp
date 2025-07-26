class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int sum=0,mx=nums[0];
        unordered_map<int,int>freq;
        for(int x:nums){
            if(x>0 and !freq[x])sum+=x;
            mx=max(mx,x);
            freq[x]++;
        }
        if(sum==0)sum=mx;
        return sum;
    }
};