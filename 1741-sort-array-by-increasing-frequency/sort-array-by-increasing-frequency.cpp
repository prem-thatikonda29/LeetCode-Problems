class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> frequencies;
        for(const auto& num : nums){
            frequencies[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(frequencies[a] != frequencies[b]){
                return frequencies[a] < frequencies[b];
            }
            return a > b;
        });

        return nums; 
    }
};