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
        vector<int> dp(n, -1);
        return helper(nums, n-1, dp);
    }
};