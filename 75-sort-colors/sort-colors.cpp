class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, j = 0, k = nums.size() - 1;
        while(j <= k){
            if(nums[j] == 0){
                swap(nums[l], nums[j]);
                l++;
                j++;
            }
            else if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};