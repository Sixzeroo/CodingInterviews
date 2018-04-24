class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int len = pushV.size();
        if(len == 0) return true;
        int j= 0;
        for(int i=0; i<len; i++)
        {
            while(j<len && (st.empty() || st.top() != popV[i]))
                st.push(pushV[j++]);
            if(st.top() == popV[i]) st.pop();
            else return false;
        }
        return true;
    }
};