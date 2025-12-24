class Solution {
private:
    long long solve(int i, int n, int k, int state, vector<int>& prices,
                    vector<vector<vector<long long>>> &dp) {
        if (i == n)
            return (state == 0) ? 0 : -1e18; // unfinished trades invalid
        if (k == 0)
            return (state == 0) ? solve(i + 1, n, k, 0, prices, dp) : -1e18;

        if(dp[i][k][state] != -1) return dp[i][k][state];

        if (state == 0) {
            return dp[i][k][state] = max({
                solve(i + 1, n, k, 0, prices, dp),
                -prices[i] + solve(i + 1, n, k, 1, prices, dp),
                +prices[i] + solve(i + 1, n, k, 2, prices, dp)
            });
        } else if (state == 1) {
            return dp[i][k][state] = max(
                solve(i + 1, n, k, state, prices, dp),
                +prices[i] + solve(i + 1, n, k - 1, 0, prices, dp)
            );
        } else { // state == 2
            return dp[i][k][state] = max(
                solve(i + 1, n, k, state, prices, dp),
                -prices[i] + solve(i + 1, n, k - 1, 0, prices, dp)
            );
        }
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,
            vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        return solve(0, n, k, 0, prices, dp);
    }
};
