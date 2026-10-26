class Solution {
    unordered_set<string> dict;
    vector<string> answer;
    vector<string> path;
    void solve(int start, string s) {
        if(start==s.size()) {
            string sentence;
            for(int i=0; i<path.size(); i++) {
                if(i>0) {
                    sentence += ' ';
                }
                sentence += path[i];
            }
            answer.push_back(sentence);
            return;
        }
        for(int end=start; end<s.size(); end++) {
            string word=s.substr(start, end-start+1);
            if(dict.find(word) != dict.end()) {
                path.push_back(word);
                solve(end+1, s);
                path.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        answer.clear();
        dict.clear();
        path.clear();
        for(string word: wordDict) {
            dict.insert(word);
        }
        solve(0, s);
        return answer;
    }
};