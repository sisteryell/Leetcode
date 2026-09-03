class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_smallest = -1;
        for (int num : nums1) {
            if ((odd_smallest == -1) and (num & 1)) {
                odd_smallest = num;
            } else if ((num & 1) and (num < odd_smallest)) {
                odd_smallest = num;
            }
        }
        if (odd_smallest % 2 == 0) {
            return true;
        }
        for (int num : nums1) {
            if ((num % 2 == 0) and (odd_smallest > num)) {
                return false;
            }
        }
        return true;
    }
};