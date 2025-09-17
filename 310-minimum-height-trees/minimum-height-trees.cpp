class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return {0};
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> adj;

        for(int i  = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        while(n > 2) {
            int size = q.size();

            for(int i = 0 ; i  < size; i++) {
                int node = q.front(); q.pop();
                n--;
                for(int v : adj[node]) {
                    indegree[v]--;
                    if(indegree[v] == 1) q.push(v); // newly formed leaves
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.emplace_back(q.front());q.pop();
        }
        return ans;
    }
};