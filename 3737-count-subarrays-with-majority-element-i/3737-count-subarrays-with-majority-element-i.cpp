class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pref(2*n+1,0);
        pref[n]=1;
        int count=n;
        long long presum=0, ans=0;
        for(int x: nums){
            if(x==target){
                presum+=pref[count];
                count++;
                pref[count]++;
            }else{
                count--;
                presum-=pref[count];
                pref[count]++;
            }
            ans+=presum;
        }   
        return ans;
    }
};