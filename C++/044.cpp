class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int zero = 0, len = numbers.size();
        if(len == 0)
            return false;
        // 记录0出现的个数
        for(int i = 0; i < len && numbers[i]  == 0; i++)
            zero++;
        for(int i = zero; i < len; i++)
        {
            if(i == zero || numbers[i] == numbers[i - 1] + 1)
                continue;
            // 重复的数字不能计入
            else if(numbers[i] == numbers[i - 1])
                return false;
            // 使用0替代其他的东西
            zero -= numbers[i] - numbers[i-1] - 1;
            if(zero < 0)
                return false;
            else
                continue;
        }
        return true;
    }
};