class Solution {
    int mod = (int)1e6;
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int count = 1;
        string source = a;
        while(source.size() < b.size()) {
            count++;
            source+=a;
        }
        if(source == b) return count;
        if(Robin(source,b)!=-1)return count;
        if(Robin(source+a,b)!=-1)return count+1;
        return -1;
    }
    int Robin(string source, string target) {
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
        for(int i=0;i<m;i++) {
            power = (power*31)%mod;
        }
        int targetcode = 0;
        for(int i=0;i<m;i++) {
            targetcode = (targetcode*31+target[i])%mod;
        }
        int hashcode = 0;
        for(int i=0;i<source.size();i++) {
            hashcode = (hashcode*31+source[i])%mod;
            if(i<m-1)continue;
            if(i>=m){
                hashcode = (hashcode-source[i-m]*power)%mod;
            }
            if(hashcode<0){
                hashcode+=mod;
            }
            if(hashcode == targetcode){
                if(source.substr(i-m+1,m) == target){
                    return i-m+1;
                }
            }
        }
        return -1;
    }
};