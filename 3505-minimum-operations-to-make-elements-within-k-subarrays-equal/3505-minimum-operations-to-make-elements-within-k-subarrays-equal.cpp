class Solution {
    class SlidingMedian{
        private:
        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;
        void rebalance() {
            int req = (low.size() + high.size() + 1) / 2;
            while(low.size() > req) {
                auto it = prev(low.end());
                long long value = *it;
                low.erase(it);
                sumLow -= value;
                high.insert(value);
                sumHigh += value;
            }
            while(low.size() < req) {
                auto it = high.begin();
                long long value = *it;
                high.erase(it);
                sumHigh -= value;
                low.insert(value);
                sumLow += value;
            }
        }
        public:
        void add(long long value) {
            if(low.empty() || value <= *low.rbegin()) {
                low.insert(value);
                sumLow += value;
            } else {
                high.insert(value);
                sumHigh += value;
            }
            rebalance();
        }
        void remove(long long value) {
            auto it = low.find(value);
            if(it != low.end()) {
                low.erase(it);
                sumLow -= value;
            } else {
                it = high.find(value);
                high.erase(it);
                sumHigh -= value;
            }
            rebalance();
        }
        long long getCost() {
            long long median = *low.rbegin();
            long long leftCost = median * (long long)low.size() - sumLow;
            long long rightCost = sumHigh - median * (long long)high.size();
            return leftCost + rightCost;
        }
    };
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        SlidingMedian window;
        for(int i = 0; i < x; i++) {
            window.add(nums[i]);
        }
        for(int i = 0; i <= n - x; i++) {
            cost[i] = window.getCost();
            if(i < n - x) {
                window.remove(nums[i]);
                window.add(nums[i + x]);
            }
        }
        const long long inf = LLONG_MAX;
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, inf);
        for(int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), inf);
            for(int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];
                if(i >= x && prev[i - x] != inf) {
                    long long take = prev[i - x] + cost[i - x];
                    curr[i] = min(curr[i], take);
                }
            }
            prev.swap(curr);
        }
        if(prev[n] == inf)return -1;
        return prev[n];
    }
};