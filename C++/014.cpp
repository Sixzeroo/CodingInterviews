class Solution {
public:
    // 需要保持相对位置不变
    void reOrderArray(vector<int> &array) {
        vector<int> evenList;
        int odd_p = 0;
        for(int i=0; i<array.size(); i++)
        {
            if(array[i] & 1) array[odd_p++] = array[i];
            else evenList.push_back(array[i]);
        }
        for(int i : evenList) array[odd_p++] = i;
    }
};

// 如果不需要保持相对位置不变，则可以采用快排变形算法