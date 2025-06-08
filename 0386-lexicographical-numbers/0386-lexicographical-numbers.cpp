class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cnt = 1;
        for(int i=0;i<n;i++) {
            ans.push_back(cnt);
            if(cnt*10 <= n) {
                cnt *= 10;
            } else {
                if(cnt >= n) cnt /= 10;
                cnt++;
                while(cnt%10 == 0) cnt /= 10;
            }
        }
        return ans;
    }
};