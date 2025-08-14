class UnionFind {
private:
    vector<int> parent, size;
    int components; // O(1) count of components

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n; // Initially, each node is its own component
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        // Merge smaller tree into larger one
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        components--; // Reduce component count only if union happened
    }

    int countComponents() const {
        return components;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind uf(n);

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(graph[i][j] == 1) {
                    uf.unite(i, j);
                }
            }
        }

        return uf.countComponents();
    }
};
