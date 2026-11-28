class Solution {
private:
    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& time,
             int i, int j, int currentTime) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0 ||
            currentTime >= time[i][j])
            return;

        time[i][j] = currentTime;

        dfs(grid, time, i - 1, j, currentTime + 1);
        dfs(grid, time, i + 1, j, currentTime + 1);
        dfs(grid, time, i, j - 1, currentTime + 1);
        dfs(grid, time, i, j + 1, currentTime + 1);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> time(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    dfs(grid, time, i, j, 0);
            }
        }

        int maxTime = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                if (time[i][j] == INT_MAX)
                    return -1;

                maxTime = max(maxTime, time[i][j]);
            }
        }

        return maxTime;
    }
};