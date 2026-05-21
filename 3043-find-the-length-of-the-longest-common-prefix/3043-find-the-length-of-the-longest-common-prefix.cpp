struct Trie{
    Trie* next[10];
    bool isEnd=0;
    Trie(){
        fill(next,next+10,(Trie*)nullptr);
    }
    ~Trie(){
        for(int i=0;i<10;i++) {
            if(next[i]!=nullptr)delete next[i];
            next[i]=nullptr;
        }
    }
    void insert(string&& word) {
        Trie* node=this;
        for(char ch:word) {
            int i=ch-'0';
            if(node->next[i]==nullptr)node->next[i]=new Trie();
            node=node->next[i];
        }
        node->isEnd=1;
    }
    int commonPrefix(string&& st) {
        Trie* node=this;
        int len=0;
        for(char ch:st) {
            int i=ch-'0';
            if(node->next[i]==nullptr)return len;
            node=node->next[i];
            len++;
        }
        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie=Trie();
        for(int x:arr2)trie.insert(to_string(x));
        int maxLen=0;
        for(int x:arr1)maxLen=max(maxLen,trie.commonPrefix(to_string(x)));
        return maxLen;
    }
};