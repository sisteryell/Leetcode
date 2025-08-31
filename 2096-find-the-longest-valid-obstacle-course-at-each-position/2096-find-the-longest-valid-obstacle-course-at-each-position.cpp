class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n),tails;
        for(int i=0;i<n;i++){
            int x=obstacles[i];
            auto it=upper_bound(tails.begin(),tails.end(),x);
            int idx=it-tails.begin();
            if(it==tails.end()){
                tails.push_back(x);
            }else{
                *it=x;
            }
            ans[i]=idx+1;
        }
        return ans;
    }
};