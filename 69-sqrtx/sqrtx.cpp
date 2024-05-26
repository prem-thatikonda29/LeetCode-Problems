class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long long square;  
        int left = 1, right = x < 46340 ? x : 46340;  

        while (left <= right) {
            int mid = left + (right - left) / 2; 
            square = (long long)mid * mid;  

            if (square == x) return mid;
            else if (square < x) left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};
