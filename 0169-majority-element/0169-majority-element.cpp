class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,element;
        for(int x:nums){
            if(count==0){
                element=x;
            }
            if(element==x)count++;
            else count--;
        }
        return element;
    }
};