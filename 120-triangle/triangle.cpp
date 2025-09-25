#include <bits/stdc++.h>
using namespace std;

struct createHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& triangle,
               unordered_map<pair<int, int>, int, createHash> &m) {
        int n = triangle.size();

        // ✅ Base case: last row
        if (i == n - 1) {
            return triangle[i][j];
        }

        // ✅ Check memoized result
        if (m.find({i, j}) != m.end()) {
            return m[{i, j}];
        }

        // ✅ Recursive case: go down or down-right
        int down = helper(i + 1, j, triangle, m);
        int diag = helper(i + 1, j + 1, triangle, m);

        return m[{i, j}] = triangle[i][j] + min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<pair<int, int>, int, createHash> m;
        return helper(0, 0, triangle, m);
    }
};
