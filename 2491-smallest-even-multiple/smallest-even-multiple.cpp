class Solution {
public:
    int smallestEvenMultiple(int n) {
        int maximum = max(n, 2);
        for(int i = n; i <= maximum * 75; i++) {
           
            if(i % n == 0 && i % 2 == 0) {
                return i; 
            }
        }
        return -1;
    }
};