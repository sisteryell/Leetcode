class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int>st;
        for(auto &f:friendships){
            auto u=f[0]-1,v=f[1]-1;
            bool ok=false;
            for(auto x:languages[u]){
                for(auto y:languages[v]){
                    if(x==y){
                        ok=true;
                        break;
                    }
                }
            }
            if(!ok){
                st.insert(u);
                st.insert(v);
            }
        }
        int ans=languages.size()+1;
        for(int i=1;i<=n;i++){
            int cans=0;
            for(auto v:st){
                bool found=false;
                for(auto l:languages[v]){
                    if(l==i){
                        found=true;
                        break;
                    }
                }
                if(!found)cans++;
            }
            ans=min(ans,cans);
        }
        return ans;
    }
};