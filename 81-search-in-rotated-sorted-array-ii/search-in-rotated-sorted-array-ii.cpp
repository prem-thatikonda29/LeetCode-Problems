class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // Corrected

        while (left <= right) {
            int mid = left + (right - left) / 2; // Corrected for overflow
            if (nums[mid] == target) return true; // Added handling for equal case
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[left] == target) return true; 
                left++;
            }
        }

        return false;
    }
};