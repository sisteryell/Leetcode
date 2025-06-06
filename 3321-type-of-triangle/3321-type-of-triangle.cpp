class Solution {
    bool check(vector<int>& nums) {
        bool possible = true;
        for(int i=0;i<3;i++) {
            if(nums[i%3]+nums[(i+1)%3]<=nums[(i+2)%3]) {
                possible = false;
                break;
            }
        }
        return possible;
    }
public:
    string triangleType(vector<int>& nums) {
        bool possible;
        possible = check(nums);
        if(!possible) return "none";
        if(nums[0]==nums[1] and nums[1]==nums[2] and nums[2]==nums[0]) return "equilateral";
        else if(nums[0]==nums[1] or nums[1]==nums[2] or nums[2]==nums[0]) return "isosceles";
        else return "scalene";
    }
};