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
    void traverse(TreeNode* thisNode, int h, int &maxh)
    {
        maxh = max(maxh, h);
        if(thisNode->left != NULL)
            traverse(thisNode->left, h+1, maxh);
        if(thisNode->right != NULL)
            traverse(thisNode->right, h+1, maxh);
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        int maxh = 0;
        traverse(pRoot, 1, maxh);
        return maxh;
    }
};