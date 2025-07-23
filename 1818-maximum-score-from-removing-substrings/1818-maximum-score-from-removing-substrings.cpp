class Solution {
    int solve(string& s, char fr, char sc, int f, string& str){
        int score=0;
        stack<char> st;
        for(char c:s){
            if(!st.empty() and st.top()==fr and c==sc){
                st.pop();
                score+=f;
            }else{
                st.push(c);
            }
        }
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        int points=0;
        string str;
        if(x>=y){
            points+=solve(s,'a','b',x,str);
            points+=solve(str,'b','a',y,str);
        }else{
            points+=solve(s,'b','a',y,str);
            points+=solve(str,'a','b',x,str);
        }
        return points;
    }
};