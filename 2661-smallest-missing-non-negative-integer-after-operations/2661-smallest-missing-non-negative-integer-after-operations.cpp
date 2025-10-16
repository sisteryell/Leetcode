class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        vector<int>freq(value,0);
        for(int &x:nums){
            int r=(x%value+value)%value;
            freq[r]++;
        }
        int mex=0;
        while(freq[mex%value]>0){
            freq[mex%value]--;
            mex++;
        }
        return mex;
    }
};