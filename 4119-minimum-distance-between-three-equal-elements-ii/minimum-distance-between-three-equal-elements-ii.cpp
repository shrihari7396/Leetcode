class Solution {
    int help(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        if(n < 3) {
            return INT_MAX;
        }

        for(int q = 0; q < n-2; q++) {
            int i = nums[q], j = nums[q+1], k = nums[q+2];
            mini = min(mini, abs(i - j) + abs(j - k) + abs(k - i));
        }
        return mini;
    }
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 0;
        int mini = INT_MAX;
        int n = nums.size();
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < n; i++) {
            hash[nums[i]].emplace_back(i);
        }
        
        for(auto& it : hash) {
            mini = min(mini, help(it.second));
        }
        return mini == INT_MAX ? -1 : mini;
    }
};