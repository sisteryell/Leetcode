// class Solution {
//     int solve(int idx,int last,vector<int>& nums, vector<vector<int>>& dp) {
//         if(idx==0){
//             if(last==1) {
//                 if(nums[idx]%2==0)return 1;
//                 else return 0;
//             }else if(last==0){
//                 if(nums[idx]%2==1)return 1;
//                 else return 0;
//             }else return 0;
//         }
//         if(dp[idx][last]!=-1)return dp[idx][last];
//         int np=solve(idx-1,last,nums,dp);
//         int p=0;
//         if(last==2){
//             if(nums[idx]%2==0)p=1+solve(idx-1,0,nums,dp);
//             else p=1+solve(idx-1,1,nums,dp);
//         }else if(last==1){
//             if(nums[idx]%2==0)p=1+solve(idx-1,0,nums,dp);
//         }else{
//             if(nums[idx]%2==1)p=1+solve(idx-1,1,nums,dp);
//         }
//         return dp[idx][last]=max(p,np);
//     }
// public:
//     int maximumLength(vector<int>& nums) {
//         int same=0,different=0;
//         int odd=0,even=0;
//         for(int x:nums){
//             if(x&1)odd++;
//             else even++;
//         }
//         same=max(odd,even);
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(3,-1));
//         different=solve(n-1,2,nums,dp);
//         return max(same,different);
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0;
        for(int x:nums){
            if(x&1)odd++;
            else even++;
        }
        int edp=0,odp=0;
        for(int x:nums){
            if(x&1){
                odp=max(odp,edp+1);
            }else{
                edp=max(edp,odp+1);
            }
        }
        return max({even,odd,edp,odp});
    }
};