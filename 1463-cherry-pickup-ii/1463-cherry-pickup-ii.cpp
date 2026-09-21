class Solution {
public:
    int f(int row, int col1, int col2, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (col1 < 0 || col1 > m - 1 || col2 < 0 || col2 > m - 1)
            return 0;
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        if (row == n - 1) {
            if (col1 == col2) {
                return grid[row][col1];
            }
            return grid[row][col1] + grid[row][col2];
        }

        int maxAns = grid[0][0];
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                if (col1 == col2) {
                    maxAns =
                        max(maxAns, grid[row][col1] + f(row + 1, col1 + d1,
                                                        col2 + d2, grid, dp));
                } else {
                    maxAns = max(
                        maxAns, grid[row][col1] + grid[row][col2] +
                                    f(row + 1, col1 + d1, col2 + d2, grid, dp));
                }
            }
        }

        return dp[row][col1][col2] = maxAns;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp);
    }
};