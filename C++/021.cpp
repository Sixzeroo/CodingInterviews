class Solution {
public:
    stack<int> real_st;
    stack<int> assist_st;
    int minv = INT_MAX;
    
    void push(int value) {
        real_st.push(value);
        minv = std::min(minv, value);
        assist_st.push(minv);
    }
    void pop() {
        real_st.pop();
        assist_st.pop();
        minv = assist_st.top();
    }
    int top() {
        return real_st.top();
    }
    int min() {
        return minv;
    }
};