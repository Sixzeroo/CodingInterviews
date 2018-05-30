class Solution
{
public:
    void push(int node) {
        push_stack.push(node);
    }

    int pop() {
        if(pop_stack.empty())
        {
            // 从push_stack中导入
            while(!push_stack.empty())
            {
                int tem = push_stack.top();
                push_stack.pop();
                pop_stack.push(tem);
            }
        }
        int tem = pop_stack.top();
        pop_stack.pop();
        return tem;
    }

private:
    stack<int> pop_stack;
    stack<int> push_stack;
};