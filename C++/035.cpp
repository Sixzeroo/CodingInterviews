class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.size();
        // 通过map建立字符到位置的映射
        unordered_map<char, int> m;
        for(int i = 0; i < len; i++)
        {
            if(m.find(str[i]) == m.end())
                m.insert(make_pair(str[i], i));
            // 出现过多次的字符通过-1进行排除
            else
                m[str[i]] = -1;
        }
        int res = INT_MAX;
        // 找到第一个位置
        for(auto item : m)
        {
            if(item.second != -1)
                res = min(res, item.second);
        }
        return res == INT_MAX ? -1 : res;
    }
};