/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2)
    {
        if(r2 == NULL) return true;
        if(r1 == NULL) return false;
        return r1->val == r2->val && isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL)
        {
            if(pRoot1->val == pRoot2->val)
                result = isSameTree(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};