class Solution {
public:
    int minInsertions(string s) {
        int insertion = 0;
        int need = 0;
        for(char ch : s) {
            if(ch == '(') {
                if(need & 1) {
                    insertion++;
                    need--;
                }
                need += 2;
            } else {
                need--;
                if (need < 0) {
                    insertion++;
                    need = 1;
                }
            }
        }
        return insertion+need;
    }
};