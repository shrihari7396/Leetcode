class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, currEdges = 0;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }
        for (auto& [_, pNum] : pointNum) {
            long long numberOfEdges = 1LL * pNum * (pNum - 1) / 2;
            ans += numberOfEdges * currEdges;
            currEdges += numberOfEdges;
        }
        return ans % mod;
    }
};