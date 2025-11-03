#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.size()) return 1;      // t completely matched
        if (i == s.size()) return 0;      // s finished but t not done
        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: skip s[i]
        int ways = dfs(i + 1, j, s, t, dp);

        // Option 2: take s[i] if it matches t[j]
        if (s[i] == t[j])
            ways += dfs(i + 1, j + 1, s, t, dp);

        return dp[i][j] = ways;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(0, 0, s, t, dp);
    }
};
