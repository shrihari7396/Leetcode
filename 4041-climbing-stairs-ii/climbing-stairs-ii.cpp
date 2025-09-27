class Solution {
private:
    int helper(int n, vector<int>& costs, vector<int>& dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mini = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            int ind = n - i;
            if(ind < 0) continue;
            mini = min(mini, helper(ind, costs, dp) + costs[n] + i *  i);
        }
        return dp[n] = mini;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.emplace(costs.begin(), 0);
        vector<int> dp(n+1, -1);
        return helper(n, costs, dp);
    }
};