class Solution {
    static int digitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    static bool compare(int a, int b) {
        int sumA = digitSum(a);
        int sumB = digitSum(b);
        
        if (sumA != sumB) {
            return sumA < sumB;
        }
        return a < b;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), compare);
        
        unordered_map<int, int> targetIndex;
        for (int i=0; i< n; i++) {
            targetIndex[sorted[i]] = i;
        }
        
        vector<bool> vis(n, false);
        int swaps = 0;
        
        for (int i=0; i<n; i++) {
            if (vis[i]) {
                continue;
            }
            int curr = i;
            int cycleSize = 0;
            
            while(!vis[curr]) {
                vis[curr] = true;
                curr = targetIndex[nums[curr]];
                cycleSize++;
            }
            if(cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }
};