class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(int x : arr1) {
            int target = x - d;
            auto it = lower_bound(arr2.begin(), arr2.end(), target);
            if(it == arr2.end() || *it > x + d) {
                ans++;
            }
        }
        return ans;
    }
};