class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        vector<int> ret;

        for(int i = 1; i <= nums.size(); i++){
            if(st.find(i) == st.end()){
                ret.push_back(i);
            }
        }

        return ret;
    }
};