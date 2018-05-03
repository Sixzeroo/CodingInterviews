class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_set<int> s;
        for(auto item : data)
        {
            auto it = s.find(item);
            if(it == s.end())
                s.insert(item);
            else
                s.erase(it);
        }
        auto it = s.begin();
        *num1 = *it;
        it++;
        *num2 = *it;
    }
};