class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        unordered_set<string>vis;
        auto dfs=[&](int r,int c,int k,auto& dfs)->bool{
            if (k==word.length()){
                return true;
            }
            if(r<0 or r>=rows or c<0 or c>=cols or vis.count(to_string(r)+","+to_string(c)) or board[r][c]!=word[k]){
                return false;
            }
            vis.insert(to_string(r)+","+to_string(c));
            bool res=dfs(r+1,c,k+1,dfs) or dfs(r-1,c,k+1,dfs) or dfs(r,c+1,k+1,dfs) or dfs(r,c-1,k+1,dfs);
            vis.erase(to_string(r)+","+to_string(c));
            return res;
        };
        unordered_map<char,int>count;
        for(char c:word){
            count[c]++;
        }
        if(count[word[0]]>count[word.back()]){
            reverse(word.begin(),word.end());
        }
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(r,c,0,dfs)){
                    return true;
                }
            }
        }
        return false;        
    }
};