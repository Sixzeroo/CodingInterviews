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
    // 使用前序遍历和对称的遍历方法判断
    bool isSymmetrical2(TreeNode* Node1, TreeNode* Node2)
    {
        if(Node1 == NULL && Node2 == NULL)
            return true;
        if(Node1 == NULL || Node2 == NULL)
            return false;
        if(Node1->val != Node2->val)
            return false;
        return isSymmetrical2(Node1->left, Node2->right) && isSymmetrical2(Node1->right, Node2->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical2(pRoot, pRoot);
    }

};