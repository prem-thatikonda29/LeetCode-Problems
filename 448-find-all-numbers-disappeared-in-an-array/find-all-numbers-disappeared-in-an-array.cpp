class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> present(n + 1, 0);

        for(int num : nums){
            present[num]++;
        }

        vector<int> disappeared;
        for(int i = 1; i <= n; i++){
            if(present[i] == 0){
                disappeared.push_back(i);
            }
        }

        return disappeared;
    }
};