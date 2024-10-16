class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int e : nums1) result.push_back(e);
        for(int e : nums2) result.push_back(e);

        sort(result.begin(), result.end());

        int size = result.size();

        if(size % 2 != 0){
            return (double)result[size / 2];;
        }
        else{
            return (double)(result[(size / 2) - 1] + result[size / 2]) / 2;
        }

        return -1.0;
    }
};