class Solution {
    bool canReach(vector<vector<int>> &dist, int safe) {
        int n = dist.size();
        if (dist[0][0] < safe or dist[n-1][n-1] < safe) {
            return false;
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0,0});
        vis[0][0] = true;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n-1 and y == n-1) {
                return true;
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >=0 and ny >= 0 and nx < n and ny < n and dist[nx][ny] >=safe and !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist (n, vector<int>(n, INT_MAX));
        queue<pair<int,int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >=0 and ny >= 0 and nx < n and ny < n and dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int low = 0, high = 2 * n;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(dist, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};