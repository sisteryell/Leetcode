class Solution {
    const int mod=1e9+7;
    int n;
    vector<vector<int>>dpScore;
    vector<vector<int>>dpWays;
    pair<int,int>dfs(int x, int y, vector<string>& board){
        if(x>=n or y>=n or board[x][y]=='X'){
            return {-1,0};
        }
        if(x==n-1 and y==n-1){
            return {0,1};
        }
        if(dpScore[x][y]!=-2){
            return {dpScore[x][y],dpWays[x][y]};
        }
        int bestScore=-1;
        long long ways=0;
        vector<pair<int,int>>dir={{1,0},{0,1},{1,1}};
        for(auto &d : dir){
            auto [score,cnt]=dfs(x+d.first, y+d.second, board);
            if(score==-1)continue;
            if(score>bestScore){
                bestScore=score;
                ways=cnt;
            }else if(score==bestScore){
                ways=(ways+cnt)%mod;
            }
        }
        if(bestScore==-1){
            dpScore[x][y]=-1;
            dpWays[x][y]=0;
            return {-1,0};
        }
        int curr=0;
        if(board[x][y]>='1' and board[x][y]<='9'){
            curr=board[x][y]-'0';
        }
        dpScore[x][y]=bestScore+curr;
        dpWays[x][y]=ways%mod;
        return {dpScore[x][y],dpWays[x][y]};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        dpScore.assign(n,vector<int>(n,-2));
        dpWays.assign(n,vector<int>(n,-2));
        auto [score,ways]=dfs(0,0,board);
        if(score==-1){
            return {0,0};
        }
        return {score,ways};
    }
};