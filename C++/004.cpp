class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0) return;
        int blankNum = 0;
        int i;
        for(i=0; str[i]!='\0'; i++)
            if(str[i] == ' ') blankNum ++;
        int strLength = i + blankNum * 2;
        if(length < strLength) return;
        str[strLength] = '\0';
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