class Solution {
public:
    // 快速幂运算
    double Power(double base, int exponent) {
        int flag = exponent<0?1:0;
        exponent = abs(exponent);
        double res = 1, tem_base = base;
        int tem_e = 1;
        while(exponent)
        {
            if(exponent & 1)
                res *= tem_base;
            tem_base = tem_base * tem_base;
            exponent = exponent >> 1;
        }
        return flag?1/res:res;
    }
};