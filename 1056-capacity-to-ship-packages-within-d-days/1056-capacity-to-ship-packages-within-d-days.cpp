class Solution {
    int day(vector<int>& weights, int capacity) {
        int sum=0,days=0;
        for(int x:weights) {
            sum+=x;
            if(sum>capacity) {
                sum=x;
                days++;
            }
        }
        return days+1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(day(weights, mid)<=days)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};