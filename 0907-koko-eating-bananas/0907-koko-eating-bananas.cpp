class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans,low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high) {
            int mid=low+(high-low)/2;
            long long hour=0;
            for(int x:piles) {
                hour+=x/mid;
                if(x%mid) hour++;
            }
            if(hour<=h){ans=mid;high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};