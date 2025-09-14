class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        auto isVowel=[](char ch){
            return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
        };
        auto transfer=[&](string &s){
            string st;
            for(char ch:s){
                ch=tolower(ch);
                st+=isVowel(ch)?'#':ch;
            }
            return st;
        };
        unordered_set<string> ws(wordlist.begin(),wordlist.end());
        unordered_map<string,string>lmp,vmp;
        for(auto& word:wordlist){
            string lower=word;
            transform(lower.begin(),lower.end(),lower.begin(),::tolower);
            string code=transfer(word);
            if(!lmp.count(lower))lmp[lower]=word;
            if(!vmp.count(code))vmp[code]=word;
        }
        vector<string>ans;
        for(auto &q:queries){
            if(ws.count(q)){
                ans.push_back(q);
                continue;
            }
            string lower=q;
            transform(lower.begin(),lower.end(),lower.begin(),::tolower);
            string code=transfer(q);
            if(lmp.count(lower)){
                ans.push_back(lmp[lower]);
            }else if(vmp.count(code)){
                ans.push_back(vmp[code]);
            }else{
                ans.push_back("");
            }
        }
        return ans;
    }
};