class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int plen = strlen(pattern), slen = strlen(str);
        vector<vector<bool> > dp(slen + 1, vector<bool> (plen + 1, false));
        dp[slen][plen] = true;
        for(int i=slen ;i>=0;--i)
        {
            for(int j=plen-1;j>=0;--j)
            {
                // 判断第一个是否匹配
                bool match = (i<slen && (str[i] == pattern[j] || pattern[j] == '.'));
                // 是*模式，两种方案，匹配/不匹配
                if(j+1 < plen && pattern[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
                // 非*模式
                else
                    dp[i][j] = (match && dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};