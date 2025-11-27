class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        // For each remainder class 0..k-1, keep minimum prefix sum seen
        vector<long long> minPref(k, LLONG_MAX);
        minPref[0] = 0;  // prefix[0] belongs to remainder 0

        long long ans = LLONG_MIN;

        for (int j = 1; j <= n; j++) {
            int r = j % k;

            if (minPref[r] != LLONG_MAX) {
                ans = max(ans, prefix[j] - minPref[r]);
            }

            minPref[r] = min(minPref[r], prefix[j]);
        }

        return ans;
    }
};
