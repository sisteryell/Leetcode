class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for (int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        vector<pair<int,int>>vec(count.begin(), count.end());
        sort(vec.begin(), vec.end(),[](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};