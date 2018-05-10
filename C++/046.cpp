class A
{
public:
    A() { N++; Sum += N;}
    
    static void reset()
    {
        N = 0;
        Sum = 0;
    }
    
    static int getSum()
    {
        return Sum;
    }
    
private:
    static int N;
    static int Sum;
};

int A::N = 0;
int A::Sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        A::reset();
        
        A *tem = new A[n];
        delete []tem;
        tem = NULL;
        
        return A::getSum();
    }
};