class Solution {
public:
    int Fibonacci(int n) {
        int a = 1, b = 1;
        if(n == 0) return 0;
        if(n<=2) return 1;
        n-=2;
        while(n--)
        {
            int tem = b;
            b = a + b;
            a = tem;
        }
        return b;
    }
};