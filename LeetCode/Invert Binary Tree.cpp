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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        TreeNode* temp = left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
    //非递归
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL) return root;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            TreeNode *temp2 = temp->left;
            temp->left = temp->right;
            temp->right = temp2;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return root;
    }
};

