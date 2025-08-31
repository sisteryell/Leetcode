class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a, const vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>tails;
        for(int i=0;i<n;i++){
            int h=envelopes[i][1];
            auto it=lower_bound(tails.begin(),tails.end(),h);
            if(it==tails.end()){
                tails.push_back(h);
            }else{
                *it=h;
            }
        }
        return (int)tails.size();
    }
};