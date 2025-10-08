class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0,diff=1e9;
        for(int i=0;i<n-2;i++){
            int lo=i+1,hi=n-1;
            while(lo<hi){
                int sum=nums[i]+nums[lo]+nums[hi];
                int curd=abs(sum-target);
                if(curd<diff or (curd==diff and sum>ans)){
                    diff=curd;
                    ans=sum;
                }
                if(sum>target)hi--;
                else lo++;
            }
        }
        return ans;
    }
};