class Solution {
private:
    int helper(int i, int target, int sum, vector<int>& nums, unordered_map<string, int>& m) {
        if(i == -1) {
            if(target == sum) return 1;
            return 0;
        }

        string hash = to_string(i) + ", " + to_string(sum);
        if(m.find(hash) != m.end()) {
            return m[hash];
        }

        int take = helper(i-1, target, sum + nums[i], nums, m);
        int notTake = helper(i - 1, target, sum - nums[i], nums, m);
        m[hash] = take + notTake;

        return  take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> m;
        return helper(nums.size()-1, target, 0, nums, m);
    }
};