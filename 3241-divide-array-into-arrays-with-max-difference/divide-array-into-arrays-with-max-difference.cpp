class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 1; i < n-1; i+=3) {
            if((nums[i] - nums[i-1] > k) || (nums[i+1] - nums[i] > k) || (nums[i+1] - nums[i-1] > k)) return {};
            ans.push_back({nums[i-1], nums[i], nums[i+1]});
        }
        return ans;
    }
};