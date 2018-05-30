class Solution {
public:
    // 利用最后一个数把前面的数分割成两堆的特性
    bool recu(vector<int> &nums, int begin, int end)
    {
        int len = nums.size();
        if(len == 0 || end < begin) return false;
        if(end == begin) return true;
        
        int m=begin;
        while(m < end)
        {
            if(nums[m] >= nums[end]) break;
            m++;
        }
        int i = m;
        while(i < end)
        {
            if(nums[i] <= nums[end]) return false;
            i++;
        }
        
        // 递归截止条件的考虑
        bool left = (m==begin)?true:recu(nums, begin, m-1);
        bool right = (i==end)?true:recu(nums, m, end-1);
        return left && right;
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        return recu(sequence, 0, len-1);
    }
};