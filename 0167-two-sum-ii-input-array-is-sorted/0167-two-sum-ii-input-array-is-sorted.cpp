class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int>ans;
        for(int i=0;i<n;i++) {
            int first = numbers[i];
            int second = target - first;
            int low = i+1, high = n-1;
            while(low<=high) {
                int mid = low + (high - low) / 2;
                if(numbers[mid]==second){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    break;
                }
                else if(numbers[mid]<second)low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
};