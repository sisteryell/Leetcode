class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==key)index.push_back(i);
        }
        set<int>ans;
        for(int x:index) {
            for(int i=x-k;i<=x+k;i++) {
                if(i>=0 and i<n)ans.insert(i);
                else if(i<0){i=0;ans.insert(i);}
                else if(i>n){i=n-1;ans.insert(i);break;}
            }
        }
        index={};
        index.insert(index.begin(),ans.begin(),ans.end());
        return index;
    }
};