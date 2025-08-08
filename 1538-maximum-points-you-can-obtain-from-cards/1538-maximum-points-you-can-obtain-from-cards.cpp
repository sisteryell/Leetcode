class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ls=0,mx=0;
        for(int i=0;i<k;i++) {
            ls+=cardPoints[i];
        }
        mx=ls;
        int rs=0;
        for(int i=1;i<=k;i++) {
            rs+=cardPoints[n-i];
            ls-=cardPoints[k-i];
            mx=max(mx,ls+rs);
        }
        return mx;
    }
};