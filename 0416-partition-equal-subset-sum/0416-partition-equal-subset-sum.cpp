class Solution {
public:
    bool check(int idx, int sum, vector<int>nums, vector<vector<int>>&dp) {
        if(sum==0) return true;
        if(idx==0) return sum==nums[0];
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = false, not_take = check(idx-1,sum,nums,dp);
        if(sum>=nums[idx]) take = check(idx-1,sum-nums[idx],nums,dp);
        return dp[idx][sum] = take or not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        if(sum&1) return false;
        sum = sum / 2;
        vector<bool> prev(sum+1,false), cur(sum+1,false);
        prev[0] = cur[0] = true;
        if(nums[0]<=sum) prev[nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool not_take = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j-nums[i]];
                cur[j] = take or not_take;
            }
            prev = cur;
        }
        return prev[sum];
    }
};