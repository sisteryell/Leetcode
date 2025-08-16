class Solution {
public:
    int maximum69Number (int num) {
        string st=to_string(num);
        int n=st.size();
        for(int i=0;i<n;i++){
            if(st[i]=='6'){
                st[i]='9';
                break;
            }
        }
        return stoi(st);
    }
};