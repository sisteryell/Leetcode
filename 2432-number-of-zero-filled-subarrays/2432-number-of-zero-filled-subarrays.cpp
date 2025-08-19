class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0,cont=0;
        for(int x:nums){
            if(x==0){
                cont++;
                cnt+=cont;
            }else{
                cont=0;
            }
        }
        return cnt;
    }
};