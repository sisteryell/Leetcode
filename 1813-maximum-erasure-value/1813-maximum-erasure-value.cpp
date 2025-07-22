class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        int sum=0,ans=0;
        unordered_set<int>seen;
        for(int i=0;i<n;i++) {
            while(seen.find(nums[i])!=seen.end()){
                sum-=nums[idx];
                seen.erase(nums[idx]);
                idx++;
            }
            sum+=nums[i];
            seen.insert(nums[i]);
            ans=max(sum,ans);
        }
        return ans;
    }
};