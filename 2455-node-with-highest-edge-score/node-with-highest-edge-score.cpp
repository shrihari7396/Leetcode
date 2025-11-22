class Solution {
private:
    int solve(int n, vector<int>& edges) {
        vector<long long> inDegrees(n, 0);

        for (int i = 0; i < n; i++) {
            int v = edges[i];
            inDegrees[v] += i;
        }

        long long maxi = *max_element(inDegrees.begin(), inDegrees.end());

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
