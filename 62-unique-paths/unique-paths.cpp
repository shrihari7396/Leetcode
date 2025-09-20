class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& dp) {
        if(i == 1 && j == 1) return 1;
        if(i < 1 || j < 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = helper(i, j-1, dp);
        int up = helper(i-1, j, dp);

        return dp[i][j] = left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(m, n, dp);
    }
};