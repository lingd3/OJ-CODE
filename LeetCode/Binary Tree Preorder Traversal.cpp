/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//递归
    vector<int> a;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        a.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return a;
    }
};
//用栈
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> a;
	if (root == NULL) return a;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		TreeNode * temp = s.top();
		s.pop();
		a.push_back(temp->val);
		if (temp->right != NULL) s.push(temp->right);
		if (temp->left != NULL) s.push(temp->left);
	}
	return a;
}







