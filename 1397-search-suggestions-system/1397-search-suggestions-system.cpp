class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        string cur="";
        vector<vector<string>>ans;
        for(char ch:searchWord){
            cur+=ch;
            vector<string>sug;
            auto it=lower_bound(products.begin(),products.end(),cur);
            for(int i=0;i<3 and it+i!=products.end();i++){
                string &st=*(it+i);
                if(st.find(cur))break;
                sug.push_back(st);
            }
            ans.push_back(sug);
        }
        return ans;
    }
};