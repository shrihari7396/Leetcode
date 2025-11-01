class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u == -1) continue;
            int time = informTime[u];
            adj[u].emplace_back(v);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});
        int timeRequired = 0;
        while(!q.empty()) {
            auto [node, currTime] = q.front();
            q.pop();
            int newTime = currTime + informTime[node];
            timeRequired = max(timeRequired, newTime);
            for (int sub : adj[node]) {
                q.push({sub, newTime});
            }
        }
        return timeRequired;
    }
};