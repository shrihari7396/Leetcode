class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if(i < 0 || j < 0) return 0;
        else if(obstacleGrid[i][j]) return 0;
        else if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(i, j-1, dp, obstacleGrid);
        int up = helper(i-1, j, dp, obstacleGrid);
        return dp[i][j] = left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp, obstacleGrid);
    }
};