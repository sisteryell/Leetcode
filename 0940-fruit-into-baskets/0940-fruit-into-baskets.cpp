class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s=0,mx=0;
        unordered_map<int,int>ump;
        for(int i=0;i<fruits.size();i++) {
            ump[fruits[i]]++;
            while(ump.size()>2){
                ump[fruits[s]]--;
                if(ump[fruits[s]]==0){
                    ump.erase(fruits[s]);
                }
                s++;
            }
            mx=max(mx,i-s+1);
        }
        return mx;
    }
};