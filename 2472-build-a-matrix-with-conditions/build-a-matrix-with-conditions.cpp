class Solution {
public:
    vector<int> topologicalSort(int k, const vector<vector<int>>& conditions) {
    vector<int> inDegree(k + 1, 0);
    unordered_map<int, vector<int>> graph;

    for (int i = 1; i <= k; ++i) {
        graph[i] = vector<int>();
    }

    for (const auto& condition : conditions) {
        graph[condition[0]].push_back(condition[1]);
        inDegree[condition[1]]++;
    }

    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() != k) {
        return {}; // return empty if it's impossible to have a valid topological sort
    }

    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
    vector<int> colOrder = topologicalSort(k, colConditions);

    if (rowOrder.empty() || colOrder.empty()) {
        return {}; // return empty matrix if topological sort is not possible
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    unordered_map<int, int> rowPosition, colPosition;

    for (int i = 0; i < k; ++i) {
        rowPosition[rowOrder[i]] = i;
        colPosition[colOrder[i]] = i;
    }

    for (int i = 1; i <= k; ++i) {
        matrix[rowPosition[i]][colPosition[i]] = i;
    }

    return matrix;
}

};