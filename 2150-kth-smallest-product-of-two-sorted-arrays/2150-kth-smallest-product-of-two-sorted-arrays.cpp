class Solution {
    long long solve(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count=0;
        for(int x:nums1) {
            if(x==0) {
                if(target>=0)count+=nums2.size();
                continue;
            }
            int low=0,high=nums2.size();
            while(low<high) {
                int mid=low+(high-low)/2;
                long long prod=1ll*x*nums2[mid];
                if(prod<=target) {
                    if(x>0)low=mid+1;
                    else high=mid;
                } else {
                    if(x>0)high=mid;
                    else low=mid+1;
                }
            }
            if(x>0)count+=low;
            else count+=(nums2.size()-low);
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10,high=1e10;
        while(low<high) {
            long long mid=low+(high-low)/2;
            if(solve(nums1,nums2,mid)<k)low=mid+1;
            else high=mid;
        }
        return low;
    }
};