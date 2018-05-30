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
    // 回溯法输出
    void backtracking(TreeNode* root, vector<int> &path, int sum, int v, vector<vector<int> > &res)
    {
        if(root == NULL) return;
        if(sum == v && root->left == NULL && root->right == NULL) 
        {
            res.push_back(path);
        }
        if(root->left != NULL)
        {
            path.push_back(root->left->val);
            sum += root->left->val;
            backtracking(root->left, path, sum, v, res);
            sum -= root->left->val;
            path.pop_back();
        }
        if(root->right != NULL)
        {
            path.push_back(root->right->val);
            sum += root->right->val;
            backtracking(root->right, path, sum, v, res);
            sum -= root->right->val;
            path.pop_back();
        }
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        path.push_back(root->val);
        backtracking(root, path, root->val, expectNumber, res);
        return res;
    }
};