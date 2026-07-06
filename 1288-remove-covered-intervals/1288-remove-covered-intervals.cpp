class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n=intervals.size();
        int left=0,right=1;
        int count=0;
        while(right<n){
            if(intervals[left][1]>=intervals[right][1]){
                count++;
                right++;
            }else{
                left=right;
                right++;
            }
        }
        return n-count;
    }
};