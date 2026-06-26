#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+(nums[i]==target?1:0);
        }
        ordered_set os;
        long long ans=0;
        os.insert(2*pref[n]-n);
        for(int i=n-1;i>=0;i--){
            long long x=2*pref[i]-i;
            long long req=os.size()-os.order_of_key(x+1);
            ans+=req;
            os.insert(x);
        }
        return ans;
    }
};