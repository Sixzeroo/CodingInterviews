class Solution {
public:
    // 快排中区分操作
    int Partition(vector<int>& input, int start, int end)
    {
        int tem = input[start];
        while(start < end)
        {
            while(start < end && tem <= input[end]) 
                end--;
            input[start] = input[end];
            while(start < end && tem >= input[start]) 
                start++;
            input[end] = input[start];
        }
        input[start] = tem;
        return start;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() == 0 || k <= 0 || k > input.size())
            return res;
        // 区分前k个数
        int l = 0, r = input.size() - 1;
        int m = Partition(input, l, r);
        while(m != k-1)
        {
            if(m > k-1)
                r = m - 1;
            else if(m < k-1)
                l = m + 1;
            m = Partition(input, l, r);
        }
        for(int i = 0; i < k; i++)
            res.push_back(input[i]);
        return res;
    }
};