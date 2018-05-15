/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        // 有右子树的情况
        if(pNode -> right != NULL)
        {
            TreeLinkNode *tem = pNode->right;
            while(tem->left != NULL)
            {
                tem = tem->left;
            }
            return tem;
        }
        // 到父节点中去找
        else if(pNode->next != NULL)
        {
            TreeLinkNode *pcurr = pNode;
            TreeLinkNode *par = pNode->next;
            while(par != NULL && pcurr == par->right)
            {
                pcurr = par;
                par = par->next;
            }
            return par;
        
        }
        return NULL;
    }
};