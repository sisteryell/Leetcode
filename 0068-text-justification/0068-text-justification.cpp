class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n=words.size();
        int i=0;
        while(i<n){
            int j=i,lineLen=0;
            while(j<n && lineLen+(int)words[j].size()+(j-i)<=maxWidth){
                lineLen+=words[j].size();
                j++;
            }
            int gaps=j-i-1;
            string line;
            if(j==n || gaps==0){
                for(int k=i;k<j;k++){
                    if(k>i)line.push_back(' ');
                    line+=words[k];
                }
                if((int)line.size()<maxWidth)
                    line.append(maxWidth-line.size(),' ');
            }else{
                int total=maxWidth-lineLen;
                int space=total/gaps;
                int extra=total%gaps;
                for(int k=i;k<j;k++){
                    line+=words[k];
                    if(k<j-1){
                        int spaces=space;
                        if((k-i)<extra)spaces++;
                        line.append(spaces,' ');
                    }
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};
