class Solution {
private:
    vector<int> solve(vector<int>& nums, int n, int j) {
        vector<int> ans;

        for(int i = 0; i < 32; i++) {
            int ind = 1 << i;
            if(ind & j) {
                ans.emplace_back(nums[i]);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1 << n;
        vector<vector<int>> ans;
        for(int i = 0; i < cnt; i++) {
            vector<int> tmp = solve(nums, n, i);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};