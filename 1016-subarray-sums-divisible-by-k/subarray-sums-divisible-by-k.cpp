class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = (sum%k + k) % k;
            ans += freq[mod];
            freq[mod]++;
        }
        return ans;
    }
};