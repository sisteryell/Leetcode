class Node{
    public:
    vector<Node*>v;
    bool isEnd;
    Node():v(26,nullptr),isEnd(false){}
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(node->v[word[i]-'a']==nullptr){
                node->v[word[i]-'a']=new Node();
            }
            node=node->v[word[i]-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(node->v[word[i]-'a']==nullptr)return false;
            node=node->v[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(node->v[prefix[i]-'a']==nullptr)return false;
            node=node->v[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */