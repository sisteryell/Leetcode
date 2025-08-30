class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9]={};
        int c[9]={};
        int b[9]={};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch=='.')continue;
                int v=ch-'1';
                int m=1<<v;
                if(r[i]&m)return false;
                r[i]=r[i]|m;
                if(c[j]&m)return false;
                c[j]=c[j]|m;
                int bi=(i/3)*3+j/3;
                if(b[bi]&m)return false;
                b[bi]=b[bi]|m;
            }
        }
        return true;
    }
};
