class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(auto& it : queries) {
            int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
            for(int i = x1; i <= x2; i++) {
                for(int j = y1; j <= y2; j++) {
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};