class Solution {
private:
    int helper(int i, vector<int>& nums, int n, vector<int>& dp) {
        if(i >= n) return 1e9;
        if(i == n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = 1e9;
        for(int j = 1; j <= nums[i]; j++) {
            int newIndex = i + j;
            if(newIndex >= n) break;
            mini = min(mini, helper(newIndex, nums, n, dp));
        }
        return dp[i] = (mini != 1e9) ? 1+mini : 1e9;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(0, nums, n, dp);
    }
};