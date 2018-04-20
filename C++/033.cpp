class Solution {
public:
    // 自定义比较函数
    static bool cmp(string a, string b)
    {
        string A = a + b;
        string B = b + a;
        return A<B;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str_numbers;
        for(auto item : numbers)
        {
            string tem = to_string(item);
            str_numbers.push_back(tem);
        }
        sort(str_numbers.begin(), str_numbers.end(), cmp);
        string res;
        for(auto &item : str_numbers)
            res += item;
        return res;
    }
};