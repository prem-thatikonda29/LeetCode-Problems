class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if the vector is empty
        if (intervals.empty()) return {};

        // Sort intervals based on start times
        sort(intervals.begin(), intervals.end());

        // vector to contain the merged array
        vector<vector<int>> merged;
        for (const auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};