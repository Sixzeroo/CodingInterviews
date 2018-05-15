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
    vector<vector<int> > Print(TreeNode* pRoot) {
        // BFS 思路进行遍历
        vector<vector<int> > res;
        vector<int> tem;
        queue<TreeNode*> que;
        que.push(pRoot);
        que.push(NULL);
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node == NULL)
            {
                if(tem.size() != 0)
                    res.push_back(tem);
                tem.clear();
                if(que.front() != NULL)
                    que.push(NULL);
            }
            else
            {
                tem.push_back(node->val);
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
        }
        return res;
    }
    
};