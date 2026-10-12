class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9+7;
        int BITS = 31;
        vector<int> bitCount(BITS, 0);
        for(int num : nums) {
            for(int bit=0; bit < BITS; bit++) {
                if(num & (1LL<<bit)) {
                    bitCount[bit]++;
                }
            }
        }
        long long answer = 0;
        for(int i=0;i<k;i++) {
            long long current = 0;
            for(int bit=0;bit<BITS;bit++) {
                if(bitCount[bit] > 0) {
                    current = current | (1LL << bit);
                    bitCount[bit]--;
                }
            }
            answer = (answer + current * current) % MOD;
        }
        return answer;
    }
};