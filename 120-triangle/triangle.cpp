
struct createHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
private:

    int helper(int i, int j, vector<vector<int>>& triangle, unordered_map<pair<int, int>, int, createHash> & m) {
        int n = triangle.size();
        if(i == n || j > i) {
            return 0;
        }
        if(m.find({i,j}) != m.end()) {
            return m[{i, j}];
        }
        int same = helper(i+1, j, triangle, m);
        int next = helper(i+1, j + 1, triangle, m);

        return m[{i,j}] = min(same, next) + triangle[i][j];

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<pair<int, int>, int, createHash> m;
        return helper(0, 0, triangle, m);
    }
};