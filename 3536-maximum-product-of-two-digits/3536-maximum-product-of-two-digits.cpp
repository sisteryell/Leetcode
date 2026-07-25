class Solution {
public:
    int maxProduct(int n) {
        vector<int> small;
        while(n) {
            int dig=n%10;
            small.push_back(dig);
            n/=10;
        }
        sort(small.rbegin(),small.rend());
        return small[0]*small[1];
    }
};