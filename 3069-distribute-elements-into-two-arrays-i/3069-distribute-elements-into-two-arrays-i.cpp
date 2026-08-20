class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> n1, n2;
        n1.push_back(nums[0]);
        n2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            if (n1.back() > n2.back()) {
                n1.push_back(nums[i]);
            } else {
                n2.push_back(nums[i]);
            }
        }
        n1.insert(n1.end(), n2.begin(), n2.end());
        return n1;
    }
};