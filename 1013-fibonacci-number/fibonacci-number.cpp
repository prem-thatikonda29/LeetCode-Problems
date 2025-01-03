class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int prev1 = 0;
        int prev2 = 1;
        int fibo;
        for(int i = 2; i <= n; i++){
            fibo = prev1 + prev2;
            prev1 = prev2;
            prev2 = fibo;
        }
        return fibo;
    }
};