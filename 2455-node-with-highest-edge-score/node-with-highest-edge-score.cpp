class Solution {
private:
    int solve(int n, vector<int>& edges) {
        vector<long long> inDegrees(n, 0);
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            int v = edges[i];
            inDegrees[v] += i;
            maxi = max(maxi, inDegrees[v]);
        }

        for (int it = 0; it < n; it++) {
            if (inDegrees[it] == maxi) {
                return it;
            }
        }
        return -1; // fix
    }

public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        return solve(n, edges);
    }
};
