class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int x1 = points[0][0], y1 = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            int x2 = points[i][0], y2 = points[i][1];
            res += max(abs(x2 - x1), abs(y2 - y1));
            x1 = x2;
            y1 = y2;
        }

        return res;
    }
};
