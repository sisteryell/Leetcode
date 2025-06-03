class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool OpenableBox = true;
        int answer = 0;

        while(!initialBoxes.empty() and OpenableBox){
            OpenableBox = false;
            vector<int> nextBoxes;
            for(int boxId : initialBoxes){
                if(status[boxId]){
                    OpenableBox = true;
                    nextBoxes.insert(end(nextBoxes),begin(containedBoxes[boxId]),end(containedBoxes[boxId]));
                    for(int keyId : keys[boxId]) {
                        status[keyId] = 1;
                    }
                    answer += candies[boxId];
                }
                else{
                    nextBoxes.push_back(boxId);
                }
            }
            swap(initialBoxes,nextBoxes);
        }
        return answer;
    }
};