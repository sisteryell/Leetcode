class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0;
        for(int x:nums){
            if(x>mx)mx=x;
        }
        int ans=0,len=0;
        for(int x:nums){
            if(x==mx)len++;
            else {ans=max(ans,len);len=0;}
        }
        return max(ans,len);
    }
};