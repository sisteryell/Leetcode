class Solution {
    int bs(vector<int>&heaters,int house){
        int low=0,high=heaters.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(heaters[mid]>=house){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        for(int house:houses){
            int idx=bs(heaters,house);
            int left=1e9,right=1e9;
            if(idx>0)left=house-heaters[idx-1];
            if(idx<heaters.size())right=heaters[idx]-house;
            ans=max(ans,min(left,right));
        }
        return ans;
    }
};