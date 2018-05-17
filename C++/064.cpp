class Solution {
public:
    // 使用两个堆来维护
    void Insert(int num)
    {
        if(l_que.size() == 0 || num < l_que.top())
            l_que.push(num);
        else
            g_que.push(num);
        if(g_que.size() > l_que.size())
        {
            int tem = g_que.top();
            g_que.pop();
            l_que.push(tem);
        }
        else if(l_que.size() > g_que.size() + 1)
        {
            int tem = l_que.top();
            l_que.pop();
            g_que.push(tem);
        }
    }

    double GetMedian()
    { 
        if(l_que.size() == 0)
            return 0;
        if(g_que.size() == l_que.size())
            return ( g_que.top() + l_que.top() * 1.0 )/ 2;
        else
            return l_que.top();
    }
private:
    // 小根堆
    priority_queue<int,vector<int>,greater<int> > g_que;
    // 大根堆
    priority_queue<int,vector<int>,less<int> > l_que;
};