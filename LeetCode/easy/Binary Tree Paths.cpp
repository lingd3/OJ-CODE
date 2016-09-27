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
    void dfs(TreeNode* root, string s, vector<string>& v) {
        if (s == "") s = s + to_string(root->val);
        else s = s + "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL) v.push_back(s);
        if(root->left != NULL) dfs(root->left, s, v);
        if(root->right != NULL) dfs(root->right, s, v);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if (root == NULL) return v;
        dfs(root, "", v);
        return v;
    }
};