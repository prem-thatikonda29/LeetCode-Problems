class Solution {
    public:
        // Merge function to merge two halves
        void merge(vector<int>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            // Create temporary arrays
            vector<int> leftArr(n1);
            vector<int> rightArr(n2);

            // Copy data to temp arrays leftArr[] and rightArr[]
            for (int i = 0; i < n1; ++i)
                leftArr[i] = arr[left + i];
            for (int i = 0; i < n2; ++i)
                rightArr[i] = arr[mid + 1 + i];

            // Merge the temp arrays back into arr[left..right]
            int i = 0; // Initial index of first subarray
            int j = 0; // Initial index of second subarray
            int k = left; // Initial index of merged subarray

            while (i < n1 && j < n2) {
                if (leftArr[i] <= rightArr[j]) {
                    arr[k] = leftArr[i];
                    ++i;
                } else {
                    arr[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }

            // Copy the remaining elements of leftArr[], if any
            while (i < n1) {
                arr[k] = leftArr[i];
                ++i;
                ++k;
            }

            // Copy the remaining elements of rightArr[], if any
            while (j < n2) {
                arr[k] = rightArr[j];
                ++j;
                ++k;
            }
        }

        // Merge sort function
        void mergeSort(vector<int>& arr, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;

                // Sort first and second halves
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                // Merge the sorted halves
                merge(arr, left, mid, right);
            }
        }

        // Function to sort the array
        vector<int> sortArray(vector<int>& nums) {
            mergeSort(nums, 0, nums.size() - 1);
            return nums;
        }
};
