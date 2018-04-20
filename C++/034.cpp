class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 0)
            return 0;
        vector<int> nums;
        nums.push_back(1);
        int a = 0, b = 0, c = 0, cur = 0;
        while(cur < index)
        {
            // 找出第一个比原来丑数数组大的数
            for(a = 0; a <= cur && 2*nums[a] <= nums[cur]; a++);
            for(b = 0; b <= cur && 3*nums[b] <= nums[cur]; b++);
            for(c = 0; c <= cur && 5*nums[c] <= nums[cur]; c++);
            nums.push_back(min(min(2*nums[a], 3*nums[b]), 5*nums[c]));
            cur++;
        }
        return nums[index-1];
    }
};