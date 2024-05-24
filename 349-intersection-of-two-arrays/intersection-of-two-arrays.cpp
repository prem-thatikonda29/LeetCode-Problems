class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> occurences1;
        unordered_map<int,int> occurences2;
        vector<int> result;
        for(int num : nums1){
            occurences1[num]++;
        }

        for(int num : nums2){
            occurences2[num]++;
        }

        for(auto num : occurences1){
            for(auto num2 : occurences2){
                if(num.first == num2.first){
                    result.push_back(num.first);
                }
            }
        }

        return result;
    }
};