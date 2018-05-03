class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();
        if(len == 0) return 0;
        int firstK = -1, lastK = -1;
        // 二分法找到第一个k
        int l = 0, r = len - 1;
        int m = (l + r)/2;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(data[m] > k)
                r = m - 1;
            else if(data[m] < k)
                l = m + 1;
            else if(m == 0 || data[m] != data[m-1])
            {
                firstK = m;
                break;
            }
            else
                r = m - 1;
        }
        // 找到最后一个k
        l = 0, r = len -1;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(data[m] > k)
                r = m - 1;
            else if(data[m] < k)
                l = m + 1;
            else if(m == len - 1 || data[m] != data[m+1])
            {
                lastK = m;
                break;
            }
            else
                l = m + 1;
        }
        return (firstK == -1)? 0 : lastK - firstK + 1;
    }
};