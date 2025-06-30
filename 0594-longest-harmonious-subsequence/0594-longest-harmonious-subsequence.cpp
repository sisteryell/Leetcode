class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        int count=0;
        for(int x:nums) {
            if(freq.find(x+1)!=freq.end()){
                count=max(count,freq[x]+freq[x+1]);
            }
        }
        return count;
    }
};