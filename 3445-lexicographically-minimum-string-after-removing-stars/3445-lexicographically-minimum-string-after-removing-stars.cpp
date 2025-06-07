class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char,vector<char>,greater<char>>pq;
        unordered_map<char,vector<int>>ump;
        vector<bool> v(n,true);
        for(int i=0;i<n;i++) {
            if(s[i] == '*') {
                char ch = pq.top();pq.pop();
                int last = ump[ch].back();
                ump[ch].pop_back();
                v[i] = false;
                v[last] = false;
            } else {
                pq.push(s[i]);
                ump[s[i]].push_back(i);
            }
        }
        string ans = "";
        for(int i=0;i<n;i++) {
            if(v[i]) ans+=s[i];
        }
        return ans;
    }
};