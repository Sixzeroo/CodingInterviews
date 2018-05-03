class Solution {
public:
    // 后序遍历思想
    bool IsBalanced(TreeNode* thisNode, int & h)
    {
        if(thisNode == NULL)
        {
            h = 0;
            return true;
        }
        int lh, rh;
        bool lb = IsBalanced(thisNode->left, lh);
        bool rb = IsBalanced(thisNode->right, rh);
        h = max(lh, rh) + 1;
        if(lb == false || rb == false)
            return false;
        else
        {
            int d = abs(lh-rh);
            if(d >= 2)
                return false;
            else 
                return true;
        }
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int tem;
        return IsBalanced(pRoot, tem);
    }
};