/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int> &pre, vector<int> &vin,int pre_ahead, int pre_behind, int vin_ahead, int vin_behind)
    {
        if(pre_ahead > pre_behind) return NULL;
        int v = pre[pre_ahead];
        TreeNode* root = new TreeNode(v);
        // 找到中序遍历的根节点下标
        int m = vin_ahead;
        for(; vin[m]!=v; m++);
        int llen = m-vin_ahead;
        // 递归构造
        // 构造左子树
        root->left = buildTree(pre, vin, pre_ahead+1, pre_ahead+llen, vin_ahead, m-1);
        // 构造右子树
        root->right = buildTree(pre, vin, pre_ahead+llen+1, pre_behind, m+1, vin_behind);
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = pre.size();
        TreeNode* res = buildTree(pre, vin, 0, len-1, 0, len-1);
        return res;
    }
};