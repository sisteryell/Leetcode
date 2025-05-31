class Solution {
public:

    pair<int,int> coord(int pos, int n){
        int r=(pos-1)/n,c=(pos-1)%n;
        int row=n-1-r;
        int col=c;
        if(r&1)col=n-1-c;
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<pair<int,int>>q;
        unordered_set<int>vis;
        q.push({1,0});
        vis.insert(1);
        while(!q.empty()){
            auto [pos,moves]=q.front();q.pop();
            for(int i=1;i<=6;i++){
                int next=pos+i;
                if(next>n*n)continue;
                auto [r,c]=coord(next,n);
                if(board[r][c]!=-1)next=board[r][c];
                if(next==n*n)return moves+1;
                if(!vis.count(next)){
                    vis.insert(next);
                    q.push({next,moves+1});
                }
            }
        }
        return -1;
    }
};