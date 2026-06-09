class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal=0, minVal=1e9;
        for(int num: nums){
            maxVal=max(maxVal,num);
            minVal=min(minVal,num);
        }
        return (long long)k*(maxVal-minVal);
    }
};