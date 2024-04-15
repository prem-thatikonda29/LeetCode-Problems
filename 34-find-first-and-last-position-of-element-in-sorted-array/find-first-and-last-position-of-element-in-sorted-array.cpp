class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }
        
        int first = -1, last = -1;
        int start = 0, end = nums.size() - 1;
        
        while(start <= end) { 
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                first = mid;
                last = mid;
                
                while(first > 0 && nums[first - 1] == target) {
                    first--;
                }
                
                while(last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                
                return {first, last};
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};