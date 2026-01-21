#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double getreverse(double n) { return 1.0 / n; }

    double bfs(int start, int end, vector<vector<pair<int, double>>>& adj,
               vector<bool>& vis) {
        queue<pair<int, double>> q;
        q.push({start, 1.0});
        vis[start] = true;
        while (!q.empty()) {
            auto [u, cal] = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                double edgeValue = adj[u][i].second;
                if (!vis[v]) {
                    if (end == v) {
                        return cal * edgeValue;
                    }
                    vis[v] = true;
                    q.push({v, cal * edgeValue});
                }
            }
        }

        return -1.000000;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, int> hash;
        int cnt = 0;

        for (auto& it : equations) {
            if (!hash.count(it[0])) {
                hash[it[0]] = cnt++;
            }
            if (!hash.count(it[1])) {
                hash[it[1]] = cnt++;
            }
        }

        vector<vector<pair<int, double>>> adj(cnt);

        int n = equations.size();
        for (int i = 0; i < n; i++) {
            int u = hash[equations[i][0]];
            int v = hash[equations[i][1]];

            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, getreverse(values[i])});
        }

        vector<double> ans;

        for (auto& it : queries) {
            vector<bool> vis(cnt, false);
            if (!hash.count(it[0]) || !hash.count(it[1])) {
                ans.push_back(-1.00000);
                continue;
            }
            int start = hash[it[0]];
            int end = hash[it[1]];
            if (start == end) {
                ans.push_back(1.00000);
            } else {
                ans.push_back(bfs(start, end, adj, vis));
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {

}
