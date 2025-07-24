class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,ans=0;
        for(int x:nums){
            if(nums[i]==1 and nums[j]==1){j++;}
            else if(nums[i]==1){ans=max(ans,j-i);i=j;j++;}
            else{i++;j++;}
        }
        return ans=max(ans,j-i);
    }
};