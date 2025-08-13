class Solution {
private:
    bool helper(int i, unordered_map<int, int>& m, int prev, int n,
                vector<int>& vec, unordered_map<long long, bool>& dp) {
        if (i == n - 1) return true;

        long long key = ((long long)i << 32) | prev;
        if (dp.find(key) != dp.end()) return dp[key];

        if (prev == 0) { // first jump must be exactly 1
            int nextPos = vec[i] + 1;
            if (m.find(nextPos) != m.end()) {
                return dp[key] = helper(m[nextPos], m, 1, n, vec, dp);
            }
            return dp[key] = false;
        }

        for (int jump = prev - 1; jump <= prev + 1; jump++) {
            if (jump > 0) {
                int nextPos = vec[i] + jump;
                if (m.find(nextPos) != m.end()) {
                    if (helper(m[nextPos], m, jump, n, vec, dp)) {
                        return dp[key] = true;
                    }
                }
            }
        }
        return dp[key] = false;
    }

public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> m;
        unordered_map<long long, bool> dp;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            m[stones[i]] = i;
        }
        return helper(0, m, 0, n, stones, dp); // start with no jump
    }
};
