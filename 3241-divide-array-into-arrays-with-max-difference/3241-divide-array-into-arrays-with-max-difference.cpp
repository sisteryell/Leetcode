class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        vector<vector<int>>ans;
        while(pq.size()>=3) {
            int low=pq.top();pq.pop();
            int mid=pq.top();pq.pop();
            int high=pq.top();pq.pop();
            if(high-low<=k) {
                ans.push_back({low,mid,high});
            }else{
                return {};
            }
        }
        return ans;
    }
};