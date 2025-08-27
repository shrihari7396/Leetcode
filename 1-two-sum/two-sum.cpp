class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];
            if (m.find(required) != m.end()) {
                return {m[required], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};