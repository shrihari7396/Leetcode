class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int f(int i, int j, vector<vector<int>>& grid, int k, int m, int n,
          int rem) {
        if (i > m - 1 || j > n - 1)
            return 0;

        int newRem = (rem + grid[i][j]) % k;

        if (i == m - 1 && j == n - 1) {
            return (newRem == 0) ? 1 : 0;
        }

        if (dp[i][j][newRem] != -1)
            return dp[i][j][newRem];

        long long ways = 0;

        ways += f(i + 1, j, grid, k, m, n, newRem);
        ways %= MOD;

        ways += f(i, j + 1, grid, k, m, n, newRem);
        ways %= MOD;

        return dp[i][j][newRem] = ways;
        ;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return f(0, 0, grid, k, m, n, 0);
    }
};