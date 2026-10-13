class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;
        for(int num : nums) {
            squares.push_back(num * num);
        }
        sort(squares.begin(), squares.end());
        int n = squares.size();
        long long score = 0;
        for(int i=0;i<n;i++) {
            if(i < n / 2) {
                score -= squares[i];
            } else {
                score += squares[i];
            }
        }
        return score;
    }
};