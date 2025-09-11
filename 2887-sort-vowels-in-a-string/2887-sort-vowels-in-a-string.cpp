class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        priority_queue<char,vector<char>,greater<char>>pq;
        string vowel="AEIOUaeiou";
        for(char ch:s){
            if(vowel.find(ch)!=string::npos){
                pq.push(ch);
            }
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(vowel.find(ch)!=string::npos){
                s[i]=pq.top();
                pq.pop();
            }
        }
        return s;
    }
};