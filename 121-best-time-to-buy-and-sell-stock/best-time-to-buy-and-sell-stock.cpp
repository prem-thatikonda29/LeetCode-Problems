class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxP = 0, prof = 0;

        while (right != prices.size()){
            if(prices[left] < prices[right]){
                prof = prices[right] - prices[left];
                maxP = max(maxP, prof);
            }
            else{
                left = right;
            }
            right++;
        }

        return maxP;
    }
};