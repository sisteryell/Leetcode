class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        int n = row*col;
        k=k%n;
        if (!k) return grid;
        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i/col][i%col], grid[j/col][j%col]);
                i++;
                j--;
            }
        };
        shift(0, n-1);
        shift(0, k-1);
        shift(k, n-1);
        return grid;
    }
};