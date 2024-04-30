class Solution {
public:
    int fib(int n) {
        if(n == 2 || n == 1) return 1;
        if(n == 0) return 0;
        int fibo = 0;
        int num1 = 0; 
        int num2 = 1;
        for(int i = 0; i < n - 1; i++){
            fibo = num1 + num2;
            num1 = num2;
            num2 = fibo;
        }
        
        return fibo;
    }
};