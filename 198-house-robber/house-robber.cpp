class Solution {
private:
    int helper(vector<int>& vec, int n, vector<int>& dp) {
        if(n == 0) return dp[n] = vec[n];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = helper(vec, n-2, dp) + vec[n];
        int notTake = helper(vec, n - 1, dp);
        return dp[n] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {    
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) {
                take += dp[i-2];
            }
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }
};