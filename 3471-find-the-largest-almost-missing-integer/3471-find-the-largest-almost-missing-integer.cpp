class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<=n-k;i++) {
            unordered_set<int>st;
            for(int j=i;j<i+k;j++) {
                st.insert(nums[j]);
            }
            for(int num:st) {
                ump[num]++;
            }
        }
        int ans=-1;
        for(auto [num,cnt]:ump) {
            if(cnt==1){
                ans=max(ans,num);
            }
        }
        return ans;
    }
};