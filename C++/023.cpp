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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode*> de;
        vector<int> res;
        if(root == NULL) return res;
        de.push_back(root);
        while(!de.empty())
        {
            TreeNode* tem = de.front();
            res.push_back(tem->val);
            de.pop_front();
            if(tem->left != NULL) de.push_back(tem->left);
            if(tem->right != NULL) de.push_back(tem->right);
        }
        return res;
    }
};