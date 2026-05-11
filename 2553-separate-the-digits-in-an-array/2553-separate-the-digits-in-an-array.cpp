class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums){
            string st=to_string(num);
            for(char ch: st){
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};