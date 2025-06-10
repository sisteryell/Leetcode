class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>freq;
        for(char ch : s) {
            freq[ch]++;
        }
        int odd=0,even=100;
        for(auto x : freq) {
            if((x.second)&1) odd = max(odd,x.second);
            else even = min(even,x.second);
        }
        int ans = odd-even;
        odd=100,even=0;
        for(auto x : freq) {
            if((x.second)&1) odd = min(odd,x.second);
            else even = max(even,x.second);
        }
        return max(ans,odd-even);
    }
};