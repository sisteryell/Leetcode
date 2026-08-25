class Solution {
    vector<int> present;
    void precompute(vector<int>& nums) {
        present.assign(101, 0);
        for (int num : nums) {
            present[num]++;
        }
    }
public:
    int missingMultiple(vector<int>& nums, int k) {
        precompute(nums);
        int ans = 0, cnt = k;
        while(ans == 0) {
            if (cnt > 100) {
                ans = cnt;
            }
            else if (present[cnt] == 0) {
                ans = cnt;
            }
            cnt = k + cnt;
        }
        return ans;
    }
};