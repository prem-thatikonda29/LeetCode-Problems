class Solution {
public:
    int solve(vector<int>& arr, int target, int idx, int sum){
        if(idx == arr.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int count = 0;
        count += solve(arr, target, idx + 1, sum + arr[idx]);
        count += solve(arr, target, idx + 1, sum - arr[idx]);

        return count;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0 , 0);
    }
};