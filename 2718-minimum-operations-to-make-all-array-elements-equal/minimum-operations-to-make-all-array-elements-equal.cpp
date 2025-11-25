class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + nums[i];

        vector<long long> ans;

        for (int q : queries) {
            int k = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long left = 0;
            if (k > 0)
                left = 1LL*q*k - prefix[k-1];

            long long right = 0;
            if (k < n)
                right = (prefix[n-1] - (k > 0 ? prefix[k-1] : 0))
                        - 1LL*q*(n-k);

            ans.push_back(left + right);
        }

        return ans;
    }
};
