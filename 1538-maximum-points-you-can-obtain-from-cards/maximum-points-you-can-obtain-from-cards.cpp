class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, ridx = cardPoints.size() - 1, maxSum = INT_MIN;

        for(int i = 0; i < k; i++) lsum += cardPoints[i];

        maxSum = lsum;

        for(int i = k - 1; i >= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[ridx];
            ridx--;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};