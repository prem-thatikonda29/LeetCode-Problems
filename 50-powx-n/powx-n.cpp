class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 && n < 0) {
            return -INFINITY;
        } else if (n == INT_MIN) {
            return 1.0 / (x * myPow(x, INT_MAX));
        }
        
        bool isNegative = n < 0;
        long long absN = abs((long long)n);

        double ans = 1.0;
        while (absN > 0) {
            if (absN % 2 == 1) {
                ans *= x;
            }
            x *= x;
            absN /= 2;
        }
        
        return isNegative ? 1 / ans : ans;
    }
};