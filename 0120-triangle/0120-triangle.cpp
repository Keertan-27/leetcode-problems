class Solution {
public:
    int f(int i, int j, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        int n = tri.size();
        if (i == n - 1)
            return tri[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int d = tri[i][j] + f(i + 1, j, tri, dp);
        int dd = tri[i][j] + f(i + 1, j + 1, tri, dp);
        return dp[i][j] = min(d, dd);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return f(0, 0, triangle, dp);
    }
};