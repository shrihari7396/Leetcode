class Solution {
private:
    long long f(vector<int>& nums, int q) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i]-q);
        }
        return ans;
    }
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }

        for(auto& it : queries) {
            int k = upper_bound(nums.begin(), nums.end(), it) - nums.begin();
            long long left = 0, right = 0;
            if(k > 0) {
                left = 1LL * k * it - prefixSum[k-1];
            }

            if(k < n) {
                right = (prefixSum[n-1] - (k > 0 ? prefixSum[k-1] : 0))
                        - 1LL*it*(n-k);
            }

            ans.emplace_back(left + right);
        }
        return ans;
    }
};