class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if(stack1.empty())
        {
            while(!stack2.empty())
            {
                int tem = stack2.top();
                stack2.pop();
                stack1.push(tem);
            }
        }
        int tem = stack1.top();
        stack1.pop();
        return tem;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};