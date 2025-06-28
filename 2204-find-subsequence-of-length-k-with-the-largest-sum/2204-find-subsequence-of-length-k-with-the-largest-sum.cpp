class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)pq.push({nums[i],i});
        vector<pair<int,int>>sorted;
        while(k--) {
            sorted.push_back(pq.top());
            pq.pop();
        }
        sort(sorted.begin(),sorted.end(),[&](pair<int,int>p1,pair<int,int>p2){
            return p1.second<p2.second;
        });
        vector<int>ans;
        for(pair<int,int> x:sorted) {
            ans.push_back(x.first);
        }
        return ans;
    }
};