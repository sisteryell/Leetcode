class Solution {
public:
    int minMaxDifference(int num) {
        string st=to_string(num);
        string mx="",mn="";
        int n=st.size();
        char ch=' ';
        for(int i=0;i<n;i++) {
            if(st[i]!='9') {
                ch=st[i];
                break;
            }
        }
        for(int i=0;i<n;i++) {
            if(st[i]==ch)mx+='9';
            else mx+=st[i];
        }
        for(int i=0;i<n;i++) {
            if(st[0]==st[i])mn+='0';
            else mn+=st[i];
        }
        return stoi(mx)-stoi(mn);
    }
};