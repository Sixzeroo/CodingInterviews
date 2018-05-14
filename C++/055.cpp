class Solution
{
public:
    Solution() : index(0)
    {
        for(int i = 0; i < 256; i++)
            hashtable[i] = -1;
    }
    
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(hashtable[ch] == -1)
             hashtable[ch] = index;
        else if(hashtable[ch] >= 0)
            hashtable[ch] = -2;
        index ++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int res = INT_MAX, minv = 0;
        for(int i = 0; i < 256; i++)
        {
            if(hashtable[i] < 0)
                continue;
            if(res > hashtable[i])
            {
                res = hashtable[i];
                minv = i;
            }
        }
        return res == INT_MAX ? '#' : minv;
    }

private:
    int hashtable[256];
    int index;
    
};