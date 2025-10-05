class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int zcnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zcnt++;
                continue;
            }
            res ^= nums[i];
        }
        if(zcnt == n) return 0;
        else if(res == 0) return n-1;
        return n;
    }
};