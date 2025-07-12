class Solution {
    bool force(vector<int>&position, int mid, int m) {
        int ball = 1, lastposition = position[0];
        for(int i=1;i<position.size();i++) {
            if(position[i]-lastposition >= mid) {
                ball++;
                lastposition = position[i];
                if(ball==m)return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = *max_element(position.begin(),position.end()) - 
                   *min_element(position.begin(),position.end());
        while(low<=high) {
            int mid = low + (high - low) / 2;
            if(force(position,mid,m))low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};