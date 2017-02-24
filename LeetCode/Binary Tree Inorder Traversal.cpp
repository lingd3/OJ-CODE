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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        inorderTraversal(root->left);
        a.push_back(root->val);
        inorderTraversal(root->right);
        return a;
    }
};
//用栈
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> a;
	if (root == NULL) return a;
	stack<TreeNode*> s;
	while (root != NULL) {
		s.push(root);
		root = root->left;
	}
	while (!s.empty()) {
		root = s.top();
		s.pop();
		a.push_back(root->val);
		if (root->right != NULL) {
			root = root->right;
			while (root != NULL) {
				s.push(root);
				root = root->left;
			}
		}
	}
	return a;
}


