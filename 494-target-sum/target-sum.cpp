class Solution {
private:
    int helper(int i, int sum, vector<int>& nums, int target, unordered_map<long long, int>& dp) {
        if (i == -1) {
            return (sum == target) ? 1 : 0;
        }
        long long key = ((long long)i << 32) | (sum + 2000); // offset sum to handle negatives
        if (dp.count(key)) return dp[key];

        int add = helper(i - 1, sum + nums[i], nums, target, dp);
        int subtract = helper(i - 1, sum - nums[i], nums, target, dp);

        return dp[key] = add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long long, int> dp;
        return helper(nums.size() - 1, 0, nums, target, dp);
    }
};
