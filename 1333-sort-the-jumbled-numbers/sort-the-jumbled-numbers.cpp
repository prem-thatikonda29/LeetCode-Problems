class Solution {
public:
    int convertToJumbled(int num, const vector<int>& mapping) {
        string numStr = to_string(num);
        string jumbledStr;
        for (char digit : numStr) {
            jumbledStr += to_string(mapping[digit - '0']);
        }
        return stoi(jumbledStr);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> jumbledMap;
        for (int num : nums) {
            jumbledMap[num] = convertToJumbled(num, mapping);
        }

        sort(nums.begin(), nums.end(), [&jumbledMap](int a, int b) {
            return jumbledMap[a] < jumbledMap[b];
        });

        return nums;
    }
};