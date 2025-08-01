class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1=nums1.size();
        while(m>0 and n>0){
            if(nums1[m-1]<=nums2[n-1]){
                nums1[len1-1]=nums2[n-1];
                n--;
            }else{
                nums1[len1-1]=nums1[m-1];
                m--;
            }
            len1--;
        }
        while(n>0){
            nums1[len1-1]=nums2[n-1];
            n--;
            len1--;
        }
    }
};