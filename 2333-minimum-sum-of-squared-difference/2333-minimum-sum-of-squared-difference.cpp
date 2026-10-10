class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long operations = (long long) k1+k2;
        vector<long long> diff(n);
        long long totalDiff = 0;
        long long maxDiff = 0;
        for(int i=0;i<n;i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            totalDiff += diff[i];
            maxDiff = max(diff[i], maxDiff);
        }
        long long low = 0, high = maxDiff;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;
            for(int i=0;i<n;i++) {
                if(diff[i] > mid) {
                    needed += diff[i] - mid;
                }
            }
            if(needed <= operations) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long target = low;
        long long used = 0;
        long long answer = 0;
        for(int i=0;i<n;i++) {
            if(diff[i] > target) {
                used += diff[i] - target;
                diff[i] = target;
            }
        }
        long long remaining = operations - used;
        for(int i=0;i<n and remaining > 0;i++) {
            if(diff[i] == target and target>0) {
                diff[i] -= 1;
                remaining -= 1;
            }
        }
        for(int i=0;i<n;i++) {
            answer += diff[i] * diff[i];
        }
        return answer;
    }
};