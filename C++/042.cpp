class Solution {
public:
    void subReverse(string &s, int a, int b)
    {
        while(a < b)
        {
            swap(s[a], s[b]);
            a++;
            b--;
        }
    }
    
    string ReverseSentence(string str) {
        int len = str.size();
        subReverse(str, 0, len - 1);
        for(int i = 0; i < len;)
        {
            int j = i + 1;
            while(j < len && str[j] != ' ')
                j++;
            subReverse(str, i, j-1);
            i = j + 1;
        }
        return str;
    }
};