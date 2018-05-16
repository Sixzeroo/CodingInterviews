/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    // 非递归中序遍历方法求出第k个数
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int cur = 0;
        TreeNode *tem = pRoot;
        stack<TreeNode*> st;
        while(tem != NULL || !st.empty())
        {
            while(tem)
            {
                st.push(tem);
                tem = tem->left;
            }
            if(!st.empty())
            {
                tem = st.top();
                st.pop();
                cur++;
                if(cur == k)
                    return tem;
                tem = tem->right;
            }
        }
        return NULL;
        
    }
};