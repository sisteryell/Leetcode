class Solution {
public:
    int maxFreqSum(string s) {
        string vowel="aeiou";
        unordered_map<char,int>v,c;
        int mv=0,mc=0;
        for(char ch:s){
            if(vowel.find(ch)!=string::npos){
                v[ch-'a']++;
                mv=max(mv,v[ch-'a']);
            }else{
                c[ch-'a']++;
                mc=max(mc,c[ch-'a']);
            }
        }
        return mv+mc;
    }
};