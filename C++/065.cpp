class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() >= size && size > 0)
        {
            // 使用双端队列存储索引下标
            deque<int> deq;
            for(int i = 0; i < size; i++)
            {
                while(!deq.empty() && num[i] >= num[deq.back()])
                    deq.pop_back();
                deq.push_back(i);
            }
            res.push_back(num[deq.front()]);
            for(int i = size; i < num.size(); i++)
            {
                while(!deq.empty() && num[i] >= num[deq.back()])
                    deq.pop_back();
                if(!deq.empty() && deq.front() <= i - size)
                    deq.pop_front();
                deq.push_back(i);
                res.push_back(num[deq.front()]);
            }
        }
        return res;
    }
};