class Solution {
public:
    bool checkValidString(string s) {
        int minn = 0, maxx = 0;
        for(char ch : s) {
            if (ch == '(') {
                minn++;
                maxx++;
            } else if (ch == ')') {
                minn--;
                maxx--;
            } else {
                minn--;
                maxx++;
            }
            if (minn < 0) minn = 0;
            if (maxx < 0) return false;
        }
        return minn == 0;
    }
};