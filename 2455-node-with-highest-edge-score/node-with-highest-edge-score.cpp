class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);

        long long maxi = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int v = edges[i];
            score[v] += i;

            if (score[v] > maxi) {
                maxi = score[v];
                ans = v;
            }
            else if (score[v] == maxi && v < ans) {
                ans = v;
            }
        }
        return ans;
    }
};
