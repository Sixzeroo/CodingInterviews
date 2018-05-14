class Solution {
public:
    void scanDigits(char **string)
    {
        while(**string != '\0' && **string >= '0' && **string <= '9')
            ++(*string);
    }
    
    bool isNumeric(char* string)
    {
        if(string == NULL) return false;
        
        // 判断前面的正负号
        if(*string == '+' || *string == '-')
            string ++;
        if(*string == '\0')
            return false;
        
        bool res = true;
        // 正式的数字
        scanDigits(&string);
        if(*string != '\0')
        {
            // 处理小数
            if(*string == '.')
            {
                string ++;
                scanDigits(&string);
            }
            // 处理科学计数法
            if(*string == 'e' || *string == 'E')
            {
                string ++;
                if(*string == '+' || *string == '-')
                    string ++;
                if(*string == '\0')
                    return false;
                scanDigits(&string);
            }
        }
        
        return (*string == '\0')? true:false;
    }

};