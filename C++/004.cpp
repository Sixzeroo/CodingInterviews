class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0) return;
        // 计算空格个数，便于后面插入字符的移动
        int blankNum = 0;
        int i;
        for(i=0; str[i]!='\0'; i++)
            if(str[i] == ' ') blankNum ++;
        int strLength = i + blankNum * 2;
        if(length < strLength) return;
        str[strLength] = '\0';
        // 采用双指针，从后往前填补，这样使用最少的空间
        int indexOrigin = i - 1, indexNew = strLength - 1;
        for(; indexOrigin>=0; indexOrigin--)
        {
            if(str[indexOrigin] == ' ')
            {
                str[indexNew--] = '0';
                str[indexNew--] = '2';
                str[indexNew--] = '%';
            }
            else
                str[indexNew--] = str[indexOrigin];
        }
	}
};