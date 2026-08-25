class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false);
        for (int num : nums) {
            present[num] = true;
        }
        for (int i = k; ; i += k) {
            if (i > 100 or !present[i]) {
                return i;
            }
        }
        return 0;
    }
};