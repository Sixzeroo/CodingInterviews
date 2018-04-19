class Solution {
public:
     int  NumberOf1(int n) {
         int res = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag) res ++;
             flag = flag << 1;
         }
         return res;
     }
};