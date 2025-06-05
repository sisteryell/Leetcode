class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> matrix(numRows);
        int i = 0, n = s.size();
        while(i<n) {
            for(int down = 0; down < numRows and i < n; down++) {
                matrix[down].push_back(s[i++]);
            }
            for(int up = numRows-2; up > 0 and i < n; up--) {
                matrix[up].push_back(s[i++]);
            }
        }
        string ans = "";
        for(int i = 0; i < numRows; i++) {
            for(char ch : matrix[i]) ans+=ch;
        }
        return ans;
    }
};