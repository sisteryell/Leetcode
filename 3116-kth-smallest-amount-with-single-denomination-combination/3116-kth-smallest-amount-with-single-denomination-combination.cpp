class Solution {
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    long long countAmounts(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;
            bool overflow = false;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;
                    l = lcm(l, coins[i]);
                    if (l > x) {
                        overflow = true;
                        break;
                    }
                }
            }
            if(overflow) {
                continue;
            }
            long long contribution = x / l;
            if(bits & 1) {
                count += contribution;
            } else {
                count -= contribution;
            }
        }
        return count;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * 1ll * k;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(countAmounts(mid, coins) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};