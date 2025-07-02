class Solution {
    bool possible(vector<int>& bloomDay, int days, int m, int k) {
        int n=bloomDay.size();
        int count=0,bouquet=0;
        for(int i=0;i<n;i++) {
            if(bloomDay[i]<=days)count++;
            else {
                bouquet+=(count/k);
                count=0;
            }
        }
        bouquet+=(count/k);
        return bouquet>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int days=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};