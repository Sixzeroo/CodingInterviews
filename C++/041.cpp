class Solution {
public:
    vector<int> getArry(int a, int b)
    {
        vector<int> res;
        for(int i = a; i <= b; i++)
            res.push_back(i);
        return res;
    }
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum == 0) return res;
        // 双指针思想
        int first = 1, second = 2, tem_sum = 3;
        while(first < second && first < tem_sum)
        {
            if(tem_sum < sum)
            {
                second ++;
                tem_sum += second;
            }
            else if(tem_sum > sum)
            {
                tem_sum -= first;
                first ++;
            }
            else
            {
                res.push_back(getArry(first, second));
                tem_sum -= first;
                first ++;
                second ++;
                tem_sum += second;
            }
        }
        return res;
    }
};