class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Check the common node between the first two edges
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};