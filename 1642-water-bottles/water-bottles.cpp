class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = 0;
        int empty = 0;

        while(numBottles > 0){
            totalDrank += numBottles;
            empty += numBottles;
            numBottles = 0;

            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return totalDrank;
    }
};