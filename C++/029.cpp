class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 使用map存放映射进行计数，因为要判断不存在的情况，时间复杂度为O(nlogn)
        map<int, int> s;
        int len = numbers.size();
        for(int i = 0; i < len; i++)
        {
            s[numbers[i]] ++;
            if(s[numbers[i]] > len/2) return numbers[i];
        }
        return 0;
    }
};