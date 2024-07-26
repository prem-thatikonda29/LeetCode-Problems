class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, numeric_limits<int>::max()));
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u][v] = w;
            graph[v][u] = w;
        }

        auto dijkstra = [&](int start) {
            vector<int> dist(n, numeric_limits<int>::max());
            dist[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, start});

            while (!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                
                if (d > dist[u]) continue;

                for (int v = 0; v < n; ++v) {
                    if (graph[u][v] < numeric_limits<int>::max()) {
                        int newDist = d + graph[u][v];
                        if (newDist < dist[v]) {
                            dist[v] = newDist;
                            pq.push({newDist, v});
                        }
                    }
                }
            }
            return dist;
        };

        int minNeighbors = numeric_limits<int>::max();
        int city = -1;

        for (int i = 0; i < n; ++i) {
            vector<int> dist = dijkstra(i);
            int count = 0;
            for (int d : dist) {
                if (d <= distanceThreshold) ++count;
            }

            if (count <= minNeighbors) {
                minNeighbors = count;
                city = i;
            }
        }

        return city;
    }
};