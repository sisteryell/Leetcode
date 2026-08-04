class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int start = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            while (nums[i] != start) {
                ans.push_back(start);
                start++;
            }
            start++;
        }
        return ans;
    }
};