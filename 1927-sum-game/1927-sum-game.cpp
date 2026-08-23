class Solution {
public:
    bool sumGame(string num) {
        int diff = 0, ques = 0;
        int n = num.size();
        for(int i = 0; i < n/2; i++) {
            if (num[i] == '?') {
                ques++;
            } else {
                diff += (num[i] - '0');
            }
        }
        for(int i = n/2; i < n; i++) {
            if (num[i] == '?') {
                ques--;
            } else {
                diff -= (num[i] - '0');
            }
        }
        if (ques & 1) {
            return true;
        }
        return diff != -9 * (ques / 2);
    }
};