class Solution {
private:
    vector<long long> findPrefix(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = capacity[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + capacity[i];
        }
        return prefixSum;
    }

public:
    long long countStableSubarrays(vector<int>& capacity) {
        vector<long long> prefixSum = findPrefix(capacity);
        map<pair<int, long long>, long long> m;
        long long ans = 0;
        int n = capacity.size();
        for(int i = n-1; i >= 0; i--) {
            ans += m[{capacity[i], (prefixSum[i]+(2*capacity[i]))}];
            if(i+1 < n) m[{capacity[i+1], prefixSum[i+1]}]++;
        }
        return ans;
    }
};
