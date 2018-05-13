class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int i = 0;
        for(; i < length; i ++)
        {
            while(numbers[i] != i)
            {
                // 判断应该在的位置是否有重复的数
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                // 转换到应该在的位置上
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};