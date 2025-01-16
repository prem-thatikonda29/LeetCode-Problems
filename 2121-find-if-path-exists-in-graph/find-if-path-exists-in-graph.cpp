class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void makeSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initially, each node is its own parent
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        makeSet(n);

        // Union all edges
        for (const auto& edge : edges) {
            unionSets(edge[0], edge[1]);
        }

        // Check if source and destination are in the same connected component
        return find(source) == find(destination);
    }
};