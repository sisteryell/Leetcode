class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int mn = *min_element(nums.begin(), nums.end());
        for(int num : nums) {
            moves += (num - mn);
        }
        return moves;
    }
};