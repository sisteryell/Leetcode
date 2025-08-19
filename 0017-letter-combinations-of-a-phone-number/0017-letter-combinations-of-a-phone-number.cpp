class Solution {
private:
    void solve(string digit,string output,int i,vector<string>& ans,string mapping[]){
        if(i>=digit.size()){
            ans.push_back(output);
            return;
        }
        int num=digit[i]-'0';
        string value=mapping[num];
        for(int j=0;j<value.size();j++){
            output.push_back(value[j]);
            solve(digit,output,i+1,ans,mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digit) {
        vector<string>ans;
        if(digit.size()==0) {
            return ans;
        }
        int i=0;
        string output;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digit,output,i,ans,mapping);
        return ans;
    }
};