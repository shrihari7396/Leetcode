class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if(i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(i, j-1, dp, grid) + grid[i][j];
        int up = helper(i-1, j, dp, grid) + grid[i][j];
        return dp[i][j] = min(left, up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m-1, n-1, dp, grid);
    }
};