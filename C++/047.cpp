class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do
        {
            // 异或算本位
            sum = num1 ^ num2;
            // 通过按位于计算进位
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }while(num2 != 0);
        return num1;
    }
};